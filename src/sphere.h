#pragma once
#include "geometry.h"
#include "material.h"

struct Sphere {
    Vec3f center;
    float radius;
    Material material;

    Sphere(const Vec3f &c, const float r, const Material &m) : center(c), radius(r), material(m) {}

    /*
     * Tests whether a given ray from orig to dest intersects with this sphere.
     * See [here](http://www.lighthouse3d.com/tutorials/maths/ray-sphere-intersection/) for further information on the algorithm.
     */
    bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const {
        Vec3f L = center - orig;
        float tca = L * dir;
        float d2 = L * L - tca * tca;

        if (d2 > radius * radius) return false;

        float thc = sqrtf(radius * radius - d2);
        t0 = tca - thc;
        float t1 = tca + thc;

        if (t0 < 0) t0 = t1;
        if (t0 < 0) return false;

        return true;
    }
};
