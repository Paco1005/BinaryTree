template <class T>
class Queue{
  private:
    class Node {
      T m_data;
      Node* m_next = nullptr;
      Node(){}
      Node(T dat) : m_data(dat) {}
      friend class Queue;
    };
    Node* m_root = nullptr;
    Node* m_last = nullptr;
    size_t m_size = 0;
  public:
    Queue() {}
    Queue(T dat) {
      m_root = new Node(dat);
      m_last = m_root;
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
void Queue<T>::push(T dat) {
  if(!m_root) {
    m_root = new Node(dat);
    m_last = m_root;
  } else if(m_root == m_last) {
    m_last = new Node(dat);
    m_root->m_next = m_last;
  } else {
    Node* tmp = new Node(dat);
    m_last->m_next = tmp;
    m_last = tmp;
  }
  m_size++;
}

/**
 *
 *
 */
template <class T>
void Queue<T>::pop() {
  if(m_root){
    Node* tmp = m_root;
    m_root = m_root->m_next;
    delete[] tmp;
    m_size--;
    if(m_size == 0) {
      m_root = nullptr;
      m_last = nullptr;
    }
  }
}

/**
 *
 *
 */
template <class T>
inline T Queue<T>::front() {
  if(!m_root) return nullptr;
  return m_root->m_data;
}

/**
 *
 *
 */
template <class T>
void Queue<T>::clear() {
  while(m_root){
    pop();
  }
}

/**
 *
 *
 */
template <class T>
inline size_t Queue<T>::size() {
  return m_size;
}