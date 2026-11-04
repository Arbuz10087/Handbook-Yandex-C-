Matrix (const Matrix<T>& other)
: rows(other.rows), columns(other.columns) {
   data = new T*[rows];
   size_t i =0;
   try {
   for (; i != rows; ++i) {
       data[i] = new T[columns];
       for (size_t j = 0; j != columns; ++j) {
           data[i][j] = other.data[i][j];
       }
   } 
  } catch (...) {
       for (size_t k =0; k != i; ++k) {
           delete [] data[k];
       }
       delete [] data;
       throw;
   }

}

Matrix (Matrix<T>&& other) {
    data = other.data;
    rows = other.rows;
    columns= other.columns;

    other.data= nullptr;
    other.rows=0;
    other.columns=0;
}


Matrix& operator= (const Matrix<T>& other) {
    if (this == &other) {
        return *this;
    }
    for (size_t i =0; i != rows; ++i) {
        delete [] data[i];
    }
    delete [] data;

    rows= other.rows;
    columns= other.columns;

     data = new T*[rows];
   size_t i =0;
   try {
   for (; i != rows; ++i) {
       data[i] = new T[columns];
       for (size_t j = 0; j != columns; ++j) {
           data[i][j] = other.data[i][j];
       }
   } 
  } catch (...) {
       for (size_t k =0; k != i; ++k) {
           delete [] data[k];
       }
       delete [] data;
       throw;
   }



    return *this;
}