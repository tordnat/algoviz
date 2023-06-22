#ifndef _VISUAL_VECTOR_H_
#define _VISUAL_VECTOR_H_

#include <iostream>
#include <vector>

//TODO: Implement some kind of limit

class VisualVector{
  private:
    std::vector<int> data;
  public:
    explicit VisualVector(const vector<int>& init_vector) : data(init_vector) {
    }

    vector<int> getVector() const {
        return myVec;
    }
};}

#endif