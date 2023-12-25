template <typename T>
class NodeOfList
{
public:
    T* date;
    NodeOfList* next;
    NodeOfList(T* val) : date(val), next(nullptr) {};
};