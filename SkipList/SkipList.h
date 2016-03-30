#define SKIP_LIST_MAX_LEVEL_COUNT 10
#define SKIP_LIST_MAX_LEVEL (SKIP_LIST_MAX_LEVEL_COUNT - 1)

struct SkipListNode {
  int key;
  int value;
  SkipListNode* forward[0];
};

class SkipList {
private:
  int level;
  SkipListNode* header;
  static int RandLevel();
  static SkipListNode* CreateNode(int key, int val, int level);
public:
  SkipList();
  bool Insert(int key, int value);
  bool Delete(int key);
  SkipListNode* Find(int key);
};
