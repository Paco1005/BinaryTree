#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"

using std::cout; using std::endl;

template <class T>
class BinaryTree {
  private:
    class NodeBT {
      private:
        T m_data;
        NodeBT* m_left = nullptr;
        NodeBT* m_right = nullptr;
        NodeBT() {}
        NodeBT(T dat) : m_data(dat) {}
      friend class BinaryTree;
    };
    NodeBT* generateNode(T dat){
      NodeBT* node = new NodeBT(dat);
      return node;
    }
    NodeBT* m_root = nullptr;
  public:
    BinaryTree() {}
    BinaryTree(T dat) {
      m_root = generateNode(dat);
    }
    void insertBFS(T dat);
    void insertDFS(T dat);
    void traverseBFS();
    void traverseDFS();
};

/**
 *
 *
 */
template<class T>
void BinaryTree<T>::insertBFS(T dat) {
  Queue<NodeBT*> q(m_root);
  NodeBT* tmp = generateNode(dat);
  while(q.size() > 0){
    if(!q.front()->m_left) {
      q.front()->m_left = tmp;
      break;
    } else if(!q.front()->m_right) {
      q.front()->m_right = tmp;
      break;
    } else {
      q.push(q.front()->m_left);
      q.push(q.front()->m_right); 
      q.pop();
    }
  }
}

/**
 *
 *
 */
template<class T>
void BinaryTree<T>::insertDFS(T dat) {
  Stack<NodeBT*> s(m_root);
  NodeBT* tmp = generateNode(dat);
  while(s.size() > 0){
    if(!s.front()->m_left) {
      s.front()->m_left = tmp;
      break;
    } else if(!s.front()->m_right) {
      s.front()->m_right = tmp;
      break;
    } else {
      s.push(s.front()->m_left);
      s.push(s.front()->m_right); 
      s.pop();
    }
  }
}

/**
 *
 *
 */
template<class T>
void BinaryTree<T>::traverseBFS() {
  Queue<NodeBT*> q(m_root);
  NodeBT* tmp = q.front();
  while(tmp){
    cout << "data: " << tmp->m_data;
    if(tmp->m_left) {
      q.push(tmp->m_left);
      cout << " Left: " << tmp->m_left->m_data;
    }
    if(tmp->m_right) {
      q.push(tmp->m_right);
      cout << " Right: " << tmp->m_right->m_data;
    }
    q.pop();
    tmp = q.front();
    cout << "\n";
  }
}

/**
 *
 *
 */
template<class T>
void BinaryTree<T>::traverseDFS() {
  Stack<NodeBT*> s(m_root);
  NodeBT* tmp = s.front();
  while(tmp){
    cout << "Parent: " << tmp->m_data;
    s.pop();
    if(tmp->m_left) {
      s.push(tmp->m_left);
      cout << " Left: " << tmp->m_left->m_data;
    }
    if(tmp->m_right) {
      s.push(tmp->m_right);
      cout << " Right: " << tmp->m_right->m_data;
    }
    tmp = s.front();
    cout << "\n";
  }
}