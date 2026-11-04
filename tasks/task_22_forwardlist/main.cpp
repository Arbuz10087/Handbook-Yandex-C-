#include <stdexcept>
#include <iostream>
#include <string>


template <typename T>
class ForwardList { 
    private:
struct Node {
    T val;
    Node* next;

    Node (const T& value) : 
    val(value), next(nullptr) {}
};
   Node* head= nullptr;

   public:

   void PushBack(const T& value) {
       Node* tail = new Node(value);
       if (!head) {
           head = tail;
       } else {
       Node* cur= head; 
      while  (cur->next != nullptr) {
           cur= cur->next;
       }
       cur->next = tail;
       }
   }


   void PushFront(const T& value) {
       Node* new_head = new Node(value);
       if (!head) {
           head = new_head;
       } else {
           Node* old_head = head;
           head = new_head;
           head->next = old_head;
       }
   }

   void PushAfter(int index, const T& value) {
     Node* newNode = new Node(value);
     Node* cur = GetNode(index);
     newNode->next = cur->next;
     cur->next= newNode;
   }

   void Delete(int index) {
       Node* cur = GetNode(index);
       if (index == 1) {
          head= cur->next;
       } else {
       Node* parent = GetNode(index-1);
       parent->next = cur->next;
       }
       delete cur;
   }

   Node* GetNode(int index) {
       Node* cur = head;
       int i=1;
       while (cur!= nullptr && i != index) {
           cur = cur->next;
           ++i;
       }
       if (cur == nullptr) {
           throw std::out_of_range("нет такого элемента");
       }
       return cur;
   }

};

int main() {
    ForwardList<int> data;
    int q;
    std::cin>> q;
    int query, x, y;
    while (q>0) {
        std::cin>> query;

        if (query== 1) {
         std::cin >> x >> y;
            if (x == 0) {
                data.PushFront(y);
            } else {
                data.PushAfter(x, y);
            }
        }

        if (query==2) {
            std::cin >> x;
            std::cout << data.GetNode(x)->val<<std::endl;
        }

        if (query == 3) {
            std::cin >> x;
            data.Delete(x);
        }
        --q;
    }

}