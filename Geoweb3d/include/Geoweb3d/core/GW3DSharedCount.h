#pragma once

#include "GW3DCheckedDelete.h"
#include "GW3DSpCountedBase.h"
#include "GW3DSpCountedImpl.h"

#include <functional>       // std::less
#include <new>              // std::bad_alloc


namespace Geoweb3d
{

namespace detail
{

struct sp_nothrow_tag {};
class gw3d_weak_count;


class gw3d_shared_count
{
private:
    GW3DSpCountedBase * pi_;
    friend class gw3d_weak_count;

public:

    gw3d_shared_count(): pi_(0)
    {
    }

    template<class Y> explicit gw3d_shared_count( Y * p ): pi_( 0 )
    {

        pi_ = new gw3d_sp_counted_impl_p<Y>( p );

        if( pi_ == 0 )
        {
            Geoweb3d::GW3DCheckedDelete( p );
            //printf("GW3D Bad Alloc\n");

        }
    }

    template<class P, class D> gw3d_shared_count( P p, D d ): pi_(0)
    {


        pi_ = new gw3d_sp_counted_impl_pd<P, D>(p, d);

        if(pi_ == 0)
        {
            d(p); // delete p
            ////printf("GW3D Bad alloc\n");
        }

    }

    template<class P, class D, class A> gw3d_shared_count( P p, D d, A a ): pi_( 0 )
    {
        typedef gw3d_sp_counted_impl_pda<P, D, A> impl_type;
        typedef typename A::template rebind< impl_type >::other A2;

        A2 a2( a );

        pi_ = a2.allocate( 1, static_cast< impl_type* >( 0 ) );

        if( pi_ != 0 )
        {
            new( static_cast< void* >( pi_ ) ) impl_type( p, d, a );
        }
        else
        {
            d( p );
            ////printf("GW3D Bad alloc\n");
        }
    }

    ~gw3d_shared_count() // nothrow
    {
        if( pi_ != 0 ) pi_->release();
    }

    gw3d_shared_count(gw3d_shared_count const & r): pi_(r.pi_) // nothrow
    {
        if( pi_ != 0 ) pi_->add_ref_copy();
    }

    explicit gw3d_shared_count(gw3d_weak_count const & r); // throws bad_weak_ptr when r.use_count() == 0
    gw3d_shared_count( gw3d_weak_count const & r, sp_nothrow_tag ); // constructs an empty *this when r.use_count() == 0

    gw3d_shared_count & operator= (gw3d_shared_count const & r) // nothrow
    {
        GW3DSpCountedBase * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if( tmp != 0 ) tmp->add_ref_copy();
            if( pi_ != 0 ) pi_->release();
            pi_ = tmp;
        }

        return *this;
    }

    void swap(gw3d_shared_count & r) // nothrow
    {
        GW3DSpCountedBase * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }

    long use_count() const // nothrow
    {
        return pi_ != 0? pi_->use_count(): 0;
    }

    bool unique() const // nothrow
    {
        return use_count() == 1;
    }

    bool empty() const // nothrow
    {
        return pi_ == 0;
    }
//SKIP-CODE-BEGIN
    friend inline bool operator==(gw3d_shared_count const & a, gw3d_shared_count const & b)
    {
        return a.pi_ == b.pi_;
    }

    friend inline bool operator<(gw3d_shared_count const & a, gw3d_shared_count const & b)
    {
        return std::less<GW3DSpCountedBase *>()( a.pi_, b.pi_ );
    }
//SKIP-CODE-END
    void * get_deleter( GW3DSpTypeinfo const & ti ) const
    {
        return pi_? pi_->get_deleter( ti ): 0;
    }
};


class gw3d_weak_count
{
private:

    GW3DSpCountedBase * pi_;
    friend class gw3d_shared_count;

public:

    gw3d_weak_count(): pi_(0) // nothrow
    {
    }

    gw3d_weak_count(gw3d_shared_count const & r): pi_(r.pi_) // nothrow
    {
        if(pi_ != 0) pi_->weak_add_ref();
    }

    gw3d_weak_count(gw3d_weak_count const & r): pi_(r.pi_) // nothrow
    {
        if(pi_ != 0) pi_->weak_add_ref();
    }

    ~gw3d_weak_count() // nothrow
    {
        if(pi_ != 0) pi_->weak_release();
    }

    gw3d_weak_count & operator= (gw3d_shared_count const & r) // nothrow
    {
        GW3DSpCountedBase * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if(tmp != 0) tmp->weak_add_ref();
            if(pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }

        return *this;
    }

    gw3d_weak_count & operator= (gw3d_weak_count const & r) // nothrow
    {
        GW3DSpCountedBase * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if(tmp != 0) tmp->weak_add_ref();
            if(pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }

        return *this;
    }

    void swap(gw3d_weak_count & r) // nothrow
    {
        GW3DSpCountedBase * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }

    long use_count() const // nothrow
    {
        return pi_ != 0? pi_->use_count(): 0;
    }

    bool empty() const // nothrow
    {
        return pi_ == 0;
    }
//SKIP-CODE-BEGIN
    friend inline bool operator==(gw3d_weak_count const & a, gw3d_weak_count const & b)
    {
        return a.pi_ == b.pi_;
    }

    friend inline bool operator<(gw3d_weak_count const & a, gw3d_weak_count const & b)
    {
        return std::less<GW3DSpCountedBase *>()(a.pi_, b.pi_);
    }
//SKIP-CODE-END
};

inline gw3d_shared_count::gw3d_shared_count( gw3d_weak_count const & r ): pi_( r.pi_ )
{
    if( pi_ == 0 || !pi_->add_ref_lock() )
    {
        ////printf("GW3D: Bad weak Pointer! Throw?\n");
    }
}

inline gw3d_shared_count::gw3d_shared_count( gw3d_weak_count const & r, sp_nothrow_tag ): pi_( r.pi_ )
{
    if( pi_ != 0 && !pi_->add_ref_lock() )
    {
        pi_ = 0;
    }
}

} // namespace detail
}//end geoweb3d