#include "closest.h"

#include "point.h"
#include "vector.h"

point closest_point_line_segment(const point &A, const point& B)
{
        float t;
        t = dot(A, A - B);
        t /= norm2(A - B);
        t = fmax(0.0f, t);
        t = fmin(1.0f, t);
        point res = A + t * (B - A);
        return res;
}

point normal_of_triangle(const point &A, const point& B, const point& C)
{
        point res = point(cross(B - A, C - A));
        return res;
}

point closest_point_triangle(const point &A, const point& B, const point& C)
{
	point n = normal_of_triangle(A, B, C);
        point n12 = point(cross(B - A, n));
        point n23 = point(cross(C - B, n));
        point n31 = point(cross(A - C, n));
        bool outer12 = dot(-A, n12) > 0;
        bool outer23 = dot(-B, n23) > 0;
        bool outer31 = dot(-C, n31) > 0;
        point on12;
        point on23;
        point on31;
        if(outer12){
            on12 = closest_point_line_segment(A, B);
        }
        if(outer23){
            on23 = closest_point_line_segment(B, C);
        }
        if(outer31){
            on31 = closest_point_line_segment(C, A);
        }
        
        point res;
        if(outer12 || outer23 || outer31){
            float inf = std::numeric_limits<float>::max();
            float min_dist = inf;
            if(outer12){
                if(min_dist > norm(on12)){
                    min_dist = norm(on12);
                    res = on12;
                }
            }
            if(outer23){
                if(min_dist > norm(on23)){
                    min_dist = norm(on23);
                    res = on23;
                }
            }
            if(outer31){
                if(min_dist > norm(on31)){
                    min_dist = norm(on31);
                    res = on31;
                }
            }     
        }else{
            res = point((dot(A, n) / norm2(n)) * n);
        } 

        return res;    
}

point closest_point_tetrahedron(const point &A, const point &B, const point &C, const point &D)
{
	point v1 = A;
        point v2 = B;
        point v3 = C;
        point v4 = D;
        float det = dot(cross(v2 - v1, v3 - v1), v4 - v1);
        if(det > 0){
            std::swap(v1, v2);
        }
        point n123 = normal_of_triangle(v1, v2, v3);
        point n134 = normal_of_triangle(v1, v3, v4);
        point n142 = normal_of_triangle(v1, v4, v2);
        point n243 = normal_of_triangle(v2, v4, v3);
        bool outer123 = dot(-v1, n123) > 0;
        bool outer134 = dot(-v1, n134) > 0;
        bool outer142 = dot(-v1, n142) > 0;
        bool outer243 = dot(-v2, n243) > 0;
        point on123, on134, on142, on243;
        if(outer123){
            on123 = closest_point_triangle(v1, v2, v3);
        }
        if(outer134){
            on134 = closest_point_triangle(v1, v3, v4);
        }
        if(outer142){
            on142 = closest_point_triangle(v1, v4, v2);
        }
        if(outer243){
            on243 = closest_point_triangle(v2, v4, v3);
        }
        point res;
        if(outer123 || outer134 || outer142 || outer243){
            float inf = std::numeric_limits<float>::max();
            float min_dist = inf;
            if(outer123){
                if(min_dist > norm(on123)){
                    min_dist = norm(on123);
                    res = on123;
                }
            }
            if(outer134){
                if(min_dist > norm(on134)){
                    min_dist = norm(on134);
                    res = on134;
                }
            }
            if(outer142){
                if(min_dist > norm(on142)){
                    min_dist = norm(on142);
                    res = on142;
                }
            }
            if(outer243){
                if(min_dist > norm(on243)){
                    min_dist = norm(on243);
                    res = on243;
                }
            }
        }else{
            res = point(0.0f, 0.0f, 0.0f);
        }
        return res; 
}
