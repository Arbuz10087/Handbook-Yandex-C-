#include <vector>

template <typename T>
class Table {
    private:
    std::vector<std::vector<T>> data;

    void makeInvariant () {
        size_t max_size = 0;
        for (const auto& elem : data) {
           if (elem.size()> max_size) {
               max_size= elem.size();
           }
        }
        for (auto& elem : data) {
            if (elem.size()< max_size) {
                elem.resize(max_size);
            }
        }
    }


    public:
    Table(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(columns);
        }
    }

    std::pair<size_t, size_t> size() const {
        if (!data.empty()) { 
        return std::make_pair(data.size(), data[0].size());
    } else {
        return {0,0};
    }
    }

    void resize(size_t n, size_t m) {
     //   if (n > data.size()) {
            data.resize(n);
     //   }
        for (auto& row : data) {
         //   if (row.size() < m) {
                row.resize(m);
      //      }
       }

       // makeInvariant();
    }

const std::vector<T>& operator[](size_t i) const {
    return data[i];
}

std::vector<T>& operator[](size_t i) {
    return data[i];
}
};