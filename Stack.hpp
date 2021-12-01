
template <class T>
class Stack{
  private:
    class Node {
      T m_data;
      Node* m_next = nullptr;
      Node(){}
      Node(T dat) : m_data(dat) {}
      friend class Stack;
    };
    Node* m_root = nullptr;
    size_t m_size = 0;
  public:
    Stack() {}
    Stack(T dat) {
      m_root = new Node(dat);
      m_size = 1;
    }
    void push(T dat);
    void pop();
    T front();
    void clear();
    size_t size();
};

/**
 *
 *
 */
template <class T>
void Stack<T>::push(T dat) {
  if(!m_root) {
    m_root = new Node(dat);
  } else {
    Node* tmp = new Node(dat);
    tmp->m_next = m_root;
    m_root = tmp;
  }
  m_size++;
}

/**
 *
 *
 */
template <class T>
void Stack<T>::pop() {
  if(m_root){
    Node* tmp = m_root;
    m_root = m_root->m_next;
    delete[] tmp;
    m_size--;
    if(m_size == 0) {
      m_root = nullptr;
    }
  }
}

/**
 *
 *
 */
template <class T>
inline T Stack<T>::front() {
  if(!m_root) return nullptr;
  return m_root->m_data;
}

/**
 *
 *
 */
template <class T>
void Stack<T>::clear() {
  while(m_root){
    pop();
  }
}

/**
 *
 *
 */
template <class T>
inline size_t Stack<T>::size() {
  return m_size;
}

