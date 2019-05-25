#include "utilities.h"
#include <math.h>

bool IvVectorUtils::isPerpendicular(IvVector3 &v1, IvVector3 &v2)
{
    float dot_result;
    dot_result = v1.Dot(v2);

    if (dot_result == 0)
    {
        return true;
    }
    return false;
}

IvVector3 IvVectorUtils::vectorProjectionX(IvVector3 &v1, IvVector3 &v2)
{

    // Here we compute the projection of v1 over v2
    if (!isZeroVector(v2))
    {
        return (v1.Dot(v2) / v2.LengthSquared()) * (v2);
    }

    // return 0 vector if v2 is 0 vector
    return IvVector3(0, 0, 0);

};

IvVector3 IvVectorUtils::vectorProjectionY(IvVector3 &v1, IvVector3 &v2)
{

    return v1 - vectorProjectionX(v1, v2);

};

float IvVectorUtils::scalarTripleProduct(IvVector3& v1, IvVector3& v2, IvVector3& v3)
{
    // Scalar triple product u dot (v x z) : This could give me area enclose by parellelloid formed by this vectors
    // Also could tell me about the direction of the angle between 2 vectors

    // if result > 0 the shorest rotation from v2 to v3 is counterclockwise
    // else is clockwise 

    return  v1.Dot(v2.Cross(v3));

};

IvVector3 IvVectorUtils::vectorTripleProduct(IvVector3 &v1, IvVector3 &v2, IvVector3 &v3)
{
    // If v1 = v3 we have v2 x v3 : which is a vector perpendicular to v2 and v3, Then v2 x ( v2 x v3)
    // which is a vector  perpendicular to v2 and ( v2 x v3) so v2, v2 x v3 , v2 x ( v2 x v3) , are orthonormal base
    // if you normalize later
    return v1.Cross(v2.Cross(v3));

}

std::vector<IvVector3*> IvVectorUtils::grandSchmidtR3(IvVector3 &v0, IvVector3 &v1, IvVector3 &v2)
{

    std::vector<IvVector3*> orthonormalSet;

    // IvVector3 w0 = v0; 
    
    // IvVector3 w1 = v1 - vectorProjectionX(v1, v0);

    // IvVector3 w2 = v2 - vectorProjectionX(v2,v0) - vectorProjectionX(v2,w1);

    // std::cout << v0 << std::endl;
    // std::cout << w1 << std::endl;
    // std::cout << w2 << std::endl;

    //orthonormalSet.push_back(&w1); // take first vector to be the first base
    //orthonormalSet.push_back(w1);
//     orthonormalSet.push_back(w2);

    return orthonormalSet;

};

std::tuple<float, float> IvVectorUtils::Cartesian2Polar(IvVector3 &v)
{
    std::tuple<float,float> polarCoordinates;

    float r = v.GetX()*v.GetX() + v.GetY()*v.GetY();

    r = static_cast<float>(sqrt(static_cast<double>(r)));

    float angle = atan2(v.GetY(), v.GetX()); // radians

    return std::make_tuple(r,angle);

}

std::tuple<float,float,float> IvVectorUtils::Cartesian2Spherical(IvVector3 &v)
{
    // std::tuple<float,float,float> spherical;

    float ro = v.Length();
    float phi = atan2(static_cast<float>(sqrt(static_cast<double>(v.GetX() * v.GetX() + v.GetY() * v.GetY()))),v.GetZ());
    float theta = atan2(v.GetY(), v.GetX());

    return std::make_tuple(ro,phi,theta);
}

// testing angles if Dot > 0 angle between vector is < 90
// testing angles if Dot < 0 angle between vector is > 90

/* Pendig to add override to print vectors on std output*/