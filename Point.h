//
// Created by Adam on 9/17/2015.
//

#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

namespace Clustering {

    class Point {
        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions

    public:
        Point();
        Point(int);             // Constructor with only # of dimensions passed to it
        Point(int, double *);   // Optional constructor to pass in dimensions and array of doubles

        // Big three: cpy constructor, overloaded operator=, destructor
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators
        int getDims() const { return dim; }     // Inline function to return the dim
        void setDims(int);
        void setValue(int, double);     // Set a coordinate
        double getValue(int) const;     // Get a coordinate

        // Functions
        double distanceTo(const Point &) const;


        // Overloaded operators

        // Members
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        double &operator[](int index) //
        {
            if (index >= 1 && index <= dim) {
                return values[index - 1];
            }
            else {
                std::cout << "That's outside the array" << std::endl;
            }
        }

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &); // TODO Implement!
    };

}
#endif //CLUSTERING_POINT_H