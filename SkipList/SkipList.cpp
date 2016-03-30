#include "SkipList.h"
#include <cstdlib>

using namespace std;

int SkipList::RandLevel() {
  int level = 0;
  while (rand() && 1 == 1) level++;
  if (level > SKIP_LIST_MAX_LEVEL) return SKIP_LIST_MAX_LEVEL;
  return level;
}

SkipListNode* SkipList::CreateNode(int key, int val, int level) {
  SkipListNode* node = (SkipListNode *)malloc(sizeof(SkipListNode) + (level + 1) * sizeof(SkipListNode*));
  node->key = key;
  node->value = val;
  return node;
}

SkipList::SkipList() {
  level = 0;
  header = CreateNode(0, 0, SKIP_LIST_MAX_LEVEL);
  for (int i = 0; i < SKIP_LIST_MAX_LEVEL; ++i) {
    header->forward[i] = nullptr;
  }
}

bool SkipList::Insert(int key, int val) {
  int level = RandLevel();
  if (level > this->level) {
    this->level = level;
  }
  SkipListNode* newNode = CreateNode(key, val, level);
  SkipListNode* preNodes[SKIP_LIST_MAX_LEVEL_COUNT];
  int iter = 0;
  while (iter <= level) {
    preNodes[iter] = header->forward[iter];
    while(preNodes[iter]->forward[iter]) {
      int nextKey = preNodes[iter]->forward[iter]->key;
      if (nextKey == key) return false;
      if (nextKey > key) break;
      preNodes[iter] = preNodes[iter]->forward[iter];
    }
    ++iter;
  }
  iter = level;
  while (iter >= 0) {
    newNode->forward[iter] = preNodes[iter]->forward[iter];
    preNodes[iter]->forward[iter] = newNode;
    --iter;
  }
  return true;
}

bool SkipList::Delete(int key) {
  SkipListNode* preNodes[SKIP_LIST_MAX_LEVEL_COUNT];
  int iter = 0;
  while (iter <= this->level) {
    preNodes[iter] = header->forward[iter];
    while (preNodes[iter]->forward[iter]) {
      int nextKey = preNodes[iter]->forward[iter]->key;
      if (nextKey >= key) break;
      preNodes[iter] = preNodes[iter]->forward[iter];
    }      
    ++iter;
  }
  iter = this->level;
  while (iter) {
    if (preNodes[iter]->forward[iter] && preNodes[iter]->forward[iter]->key == key) {
      preNodes[iter]->forward[iter] = preNodes[iter]->forward[iter]->forward[iter];
      if (iter == this->level) --this->level;
    }
    --iter;
  }
  if (preNodes[0]->forward[0] && preNodes[0]->forward[0]->key == key) {
    SkipListNode* next = preNodes[0]->forward[0]->forward[0];
    delete preNodes[0]->forward[0];
    preNodes[0]->forward[0] = next;
    return true;
  }
  else
    return false;
}

SkipListNode* SkipList::Find(int key) {
  int level = this->level;
  SkipListNode* ptr = this->header->forward[level];
  while (level >= 0 && ptr && ptr->key != key) {
    if (!ptr->forward[level] || ptr->forward[level]->key > key) {
      --level;
      continue;
    }
    ptr = ptr->forward[level];
  }
  if (ptr && ptr->key == key)
    return ptr;
  else
    return nullptr;
}
