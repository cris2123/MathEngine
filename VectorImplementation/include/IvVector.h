#include <math.h>
#include <assert.h>
#include <iostream>

#pragma once

class IvVector3
{

    public: 
        inline IvVector3() {}
        inline IvVector3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

        inline ~IvVector3(){}
        IvVector3(const IvVector3& vector);

        // Operators to overload
        // IvVector3& operator=(const IvVector3 &vector);
        // friend IvVector3 operator+(const IvVector3 &v0, const IvVector3 &v1);
        // friend IvVector3 operator*(float a, const IvVector3 &v);
        // friend IvVector3 operator*(const IvVector3 &v, float a);
        // friend IvVector3 operator/(const IvVector3 &v, float a);
        // friend IvVector3 operator*=(const IvVector3 &v, float a);
        // friend IvVector3 operator/=(const IvVector3 &v, float a);

        // IvVector3& operator=(const IvVector3 &v) 

        // {       
        //     return *this;
        
        // };

        friend IvVector3 operator+(const IvVector3 &v0, const IvVector3 &v1)
        {

            return IvVector3(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
        };

        friend IvVector3 operator-(const IvVector3 &v0, const IvVector3 & v1)
        {
            return IvVector3(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);
        };

        friend IvVector3 operator*(float a, const IvVector3 &v)
        {
            return IvVector3(a * v.x, a * v.y, a * v.z);
        };

        friend IvVector3 operator*(const IvVector3 &v, float a)
        {
            return IvVector3(a * v.x, a * v.y, a * v.z);
        };

        friend IvVector3 operator/(const IvVector3 &v, float a)
        {

            return IvVector3(v.x / a, v.y / a, v.z / a);
        };

        friend IvVector3 operator*=(const IvVector3 &v, float a)
        {

            return IvVector3(a * v.x, a * v.y, a * v.z);
        };

        friend IvVector3 operator/=(const IvVector3 &v, float a)
        {

            return IvVector3(v.x / a, v.y / a, v.z / a);
        };

        friend std::ostream& operator<<(std::ostream &os, const IvVector3& v)
        {
            return os << "(" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
        }

        // vectors basic operations
        const float Length();
        const float LengthSquared();
        IvVector3& Normalize();
        float Dot(IvVector3& other);
        friend bool isZeroVector(IvVector3& v);
        IvVector3 Cross( const IvVector3& other);

        // This class also could act like a point
        float Distance(const IvVector3& point1, const IvVector3& point2);
        float DistanceSquared(const IvVector3& point1, const IvVector3& point2);

        // setters and getters 
        inline float GetX() { return x; }
        inline float GetY() { return y; }
        inline float GetZ() { return z; }

        inline void SetX( float xVal ) { x = xVal; }
        inline void SetY(float yVal) { y = yVal; }
        inline void SetZ(float zVal) { z = zVal; }

        

        
    private:
        float x,y,z;

};



// Operators definition

// IvVector3 operator+(const IvVector3 &v0, const IvVector3 &v1)
// {

//     return IvVector3(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);
// };

// IvVector3 operator*(float a, const IvVector3 &v)
// {
//     return IvVector3(a * v.x, a * v.y, a * v.z);
// };

// IvVector3 operator*(const IvVector3 &v, float a)
// {
//     return IvVector3(a * v.x, a * v.y, a * v.z);
// };

// IvVector3 operator/(const IvVector3 &v, float a){

//     return IvVector3(v.x/a , v.y/a , v.z/a);

// };

// IvVector3 operator*=(const IvVector3 &v, float a){

//     return IvVector3(a * v.x, a *v.y, a *v.z);
    
// };

// IvVector3 operator/=(const IvVector3 &v, float a)
// {

//     return IvVector3(v.x / a, v.y / a, v.z / a);
// };