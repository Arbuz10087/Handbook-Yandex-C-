#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>



struct Weight {
  int w;
  size_t i;

  bool operator < (const Weight& other) const {
      if (w == other.w) {
          return i > other.i;
      }
  return w < other.w;
  }
};

struct Volume {
   int v;
   size_t i;

   bool operator < (const Volume& other) const {
       if (v == other.v) {
           return i > other.i;
       }
       return v < other.v;
   }

};


class Stock {
  private:

  std::set<Weight> sortedByW;
  std::set<Volume> sortedByV;
  std::vector<std::pair<std::set<Weight>::iterator, std::set<Volume>::iterator>> boxes;
  size_t current_index=0;


  public:
  void Add(int w, int v);
  int GetByW (int min_w);
  int GetByV (int min_v);


};

void Stock::Add(int w, int v) {
   boxes.push_back({sortedByW.insert({w, current_index}).first, sortedByV.insert({v, current_index}).first});
   ++current_index;
}


int Stock::GetByW (int min_w) {
  auto it = sortedByW.lower_bound({min_w, current_index});
  if (it == sortedByW.end()) {
    return -1;
  }
  int index = it->i;
  sortedByW.erase(it);
  sortedByV.erase(boxes[index].second);
  return index;
}

int Stock::GetByV (int min_v) {
    auto it = sortedByV.lower_bound({min_v, current_index});
    if (it == sortedByV.end()) {
        return -1;
    }
    int index = it->i;
    sortedByV.erase(it);
    sortedByW.erase(boxes[index].first);
    return index;
}