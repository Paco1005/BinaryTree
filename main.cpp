#include "BinaryTree.hpp"

int main() {
  BinaryTree<int> bts(1);
  bts.traverseBFS();
  bts.insertBFS(12);
  bts.insertBFS(13);
  bts.insertBFS(24);
  bts.insertBFS(24);
  bts.insertBFS(31);
  bts.insertBFS(32);
  bts.traverseBFS();
  std::cout <<"\n";
  
  BinaryTree<int> bt(10);
  bt.insertDFS(101);
  bt.insertDFS(102);
  bt.insertDFS(201);
  bt.insertDFS(202);
  bt.traverseDFS();
}