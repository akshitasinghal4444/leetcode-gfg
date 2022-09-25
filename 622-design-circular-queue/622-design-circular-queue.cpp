class MyCircularQueue {
public:
    int n,front,rear;
    vector<int> a;
    
    MyCircularQueue(int k) {
        n=k;
        a.resize(n);
        front=rear=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return 0;
        
        rear=(rear+1)%n;
        a[rear]=value;
        
        if(front==-1)
            front=0;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return 0;
        
        front=(front+1)%n;
        if(front==(rear+1)%n)
            front=rear=-1;
        
        return 1;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        
        return a[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        
        return a[rear];
    }
    
    bool isEmpty() {
        return front==-1 && rear==-1;
    }
    
    bool isFull() {
        return (rear+1)%n==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */