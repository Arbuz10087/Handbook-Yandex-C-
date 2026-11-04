#include <algorithm>
#include <iterator>

bool Tree::Has(const std::vector<std::string>& node) const {
 const Node* current= &root;
  for (const std::string& elem : node) {
      if (current->children.find(elem)!= current->children.end()) {
        current= &current->children.at(elem);
      } else {
          return false;
      }
  }

  return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
  Node* current =&root;
  for (const std::string& elem : node) {
    if (current->children.find(elem)== current->children.end()) {
      current->children[elem];
    }
      current= &current->children.at(elem);
}
}