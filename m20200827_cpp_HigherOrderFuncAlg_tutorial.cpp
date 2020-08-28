#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

struct Point3d {
    using Double = double; 
    Double x;
    Double y;
    Double z;    
};

int main ()
{
    
    std::vector<int> nums { 1, 2, 3, 4, 5, 10, 311, 32, 3 };
    std::vector<Point3d> pointcloud { Point3d{1, 2, 3}, Point3d{4, 5, 10}, Point3d{311, 32, 3} };

    // for int vec
    auto filterOdd = [](int n) {
        return n%2 == 1;
    };
    nums.erase( std::remove_if(nums.begin(), nums.end(), filterOdd) );

    for(auto& _num: nums) {
        std::cout << _num << std::endl;
    }

    // for Point3d vec
    auto normalizePoint = [](Point3d & _p) {
        float len = std::sqrt( _p.x*_p.x + _p.y*_p.y + _p.z*_p.z );
        _p.x /= len;
        _p.y /= len;
        _p.z /= len;
    };
    std::for_each(pointcloud.begin(), pointcloud.end(), normalizePoint);
    //nums.erase( std::remove_if(nums.begin(), nums.end(), normalizePoint) );

    for(auto& _p: pointcloud) {
        std::cout << "Normalized Point: " << _p.x << ", " << _p.y << ", " << _p.z << std::endl;
    }

    return 0;
}
