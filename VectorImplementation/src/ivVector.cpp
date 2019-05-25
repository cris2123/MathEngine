#include "IvVector.h"
#include <math.h>

const float IvVector3::Length()
{
    float squaredNumbers = x * x + y * y + z * z;
    return(static_cast<float>(sqrt(static_cast<double>(squaredNumbers))));
};

const float IvVector3::LengthSquared()
{
    return (x*x + y*y + z*z);
}

IvVector3& IvVector3::Normalize()
{

    /*****
    // would be better calculate inverse square root data
    // float lengthsq = LengthSquared();
    // assert( lengthsq != 0 );
    // if( lengthsq  == 0 )
    // {
    //     x = y = z = 0.0f;
    //     return *this;
    // }
    // here calculate inverse sqrt root, is better
    *********/
    float recip = 1 / Length();

    x *= recip;
    y *= recip;
    z *= recip;

    return *this;
};

float IvVector3::Dot(IvVector3& other)
{
    return x*other.x + y*other.y + z*other.z;
}

IvVector3 IvVector3::Cross(const IvVector3 &other)
{
    return IvVector3( y*other.z -other.y*z , z*other.x - other.z*x, x*other.y -other.x*y );
}

bool isZeroVector(IvVector3 &v)
{

    if (v.x == 0 && v.y == 0 && v.z == 0)
    {
        return true;
    }

    return false;
};

float IvVector3::Distance(const IvVector3 &point1, const IvVector3 &point2)
{
    float x = point1.x - point2.x;
    float y = point1.y - point2.y;
    float z = point1.z - point2.z;

    return (static_cast<float>(sqrt(static_cast<double>(x*x + y*y + z*z))));
}

float IvVector3::DistanceSquared(const IvVector3 &point1, const IvVector3 &point2)
{
    float x = point1.x - point2.x;
    float y = point1.y - point2.y;
    float z = point1.z - point2.z;

    return (x * x + y * y + z * z);
}