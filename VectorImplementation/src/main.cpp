#include <iostream>
#include "IvVector.h"
#include "utilities.h"

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;

    IvVector3 vect(1,1,1);
    IvVector3 vect2(3,2,1);

    IvVector3 z;

    z = vect + vect2;

    float dot_product_result;
    
    std::cout << vect.Length() << std::endl;
    //vect.SetX(2);
    
    std::cout << vect.GetX() << std::endl;
    std::cout << z.GetX() << std::endl;

    dot_product_result = vect2.Dot(vect);

    std::cout << "Dot product result" << std::endl;
    std::cout << dot_product_result << std::endl;

    IvVector3 testZero(1,0,0);
    std::cout << isZeroVector(testZero) << std::endl;

    IvVector3 projection = IvVectorUtils::vectorProjectionX(vect2,vect);

    // std::cout << projection.GetX() << std::endl;
    // std::cout << projection.GetY() << std::endl;
    // std::cout << projection.GetZ() << std::endl;
    std::cout << projection << std::endl;

    // testing projection function
    std::vector<IvVector3*> test;

    test = IvVectorUtils::grandSchmidtR3(vect,vect2,z);

    IvVector3 orthonormal = IvVectorUtils::vectorTripleProduct(vect,vect2,z);


    std::cout << "Triple products: " << orthonormal << std::endl;

    std::cout << "Cross product : " << vect2.Cross(z) << std::endl;
    std::cout << "Scalr triple product : " << IvVectorUtils::scalarTripleProduct(vect, vect2, z) << std::endl;

    std::cout << "Distance Squared: " << vect2.Distance(vect2,z) << std::endl;

    
}