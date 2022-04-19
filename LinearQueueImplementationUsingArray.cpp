#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class LinearQueue
{
public:
    LinearQueue(int size) :front(-1), rear(-1), qSize(100)
    {
        qContainer = new int[100];
    }

    void insert(std::vector<int> inputVect)
    {
        if (rear == (qSize - 1))
        {
            std::cout << "Queue already full" << std::endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            for (auto x : inputVect)
            {
                rear++;
                qContainer[rear] = x;
            }
        }
    }

    void deleteQElements()
    {
        if (front == -1 || front > rear)
        {
            std::cout << "Queue underflow" << std::endl;
            return;
        }
        std::cout << "Deleted element: " << qContainer[front] << std::endl;
        front++;
    }   

    void display()
    {
        if (front == -1 || front > rear)
        {
            std::cout << "Queue underflow" << std::endl;
            return;
        }

        for (auto i = front; i < rear; i++)
        {
            std::cout << qContainer[i] << " ";
        }
    }

private:
    int front = -1;
    int rear = -1;
    int* qContainer = nullptr;//User can set based on need
    int qSize = 0;
};



int main()
{ 
    //Set the size of Queue to 20 ints
    LinearQueue obj(20);
    std::vector<int> myVect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    obj.insert(myVect);
    obj.display();
    obj.deleteQElements();
    obj.display();
    obj.deleteQElements();
    obj.display();
    return 0;
}