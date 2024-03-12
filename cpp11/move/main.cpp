#include <cstdint>
#include <gtest/gtest.h>

class LinkedList {
private:
    class Node {
    public:
        Node(int32_t value)
            : _value(value)
            , _next(nullptr)
        {
        }
        void setNext(Node* next)
        {
            _next = next;
        }
        int32_t value()
        {
            return _value;
        }

    private:
        int32_t _value;
        Node* _next;
    };
    Node* _front;

public:
    LinkedList()
        : _front(nullptr)
    {
    }
    LinkedList(const LinkedList& rhs);
    LinkedList(LinkedList&& rhs)
    {
    }

    Node* front()
    {
        return _front;
    }
    void deinit()
    {
    }
    void push_back(int32_t value)
    {
        if (_front == nullptr) {
            _front = new Node(value);
        }
    }
};

TEST(testLinkedList, test1)
{
    LinkedList list;
    list.push_back(1);
    EXPECT_EQ(list.front->value(), 1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
