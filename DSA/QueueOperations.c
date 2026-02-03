                                                                    //QueueOperations//

//Aim: To perform queue operations using array//

🧭 Algorithm
ENQUEUE Operation
Step 1: Check if rear == MAX - 1.
Step 2: If true, display "Queue Overflow".
Step 3: Else if front == -1, set front = 0.
Step 4: Increment rear by 1.
Step 5: Set queue[rear] = item.
Step 6: End ENQUEUE operation.

DEQUEUE Operation
Step 1: Check if front == -1 OR front > rear.
Step 2: If true, display "Queue Underflow".
Step 3: Else set item = queue[front].
Step 4: Increment front by 1.
Step 5: Return deleted item.

PEEK Operation
Step 1: Check if front == -1 OR front > rear.
Step 2: If true, display "Queue is Empty".
Step 3: Else set item = queue[front].
Step 4: Display item.
Step 5: End PEEK operation.

DISPLAY Operation
Step 1: Check if queue is empty (front == -1 OR front > rear).
Step 2: If empty, print "Queue is Empty".
Step 3: Else print all elements from index front to rear.

🧭 Code: Queue Implementation Using Array
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// ENQUEUE operation
void enqueue(int x)
{
    // Check for queue overflow
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;  // First element entering queue

        rear++;
        queue[rear] = x;  // Insert element
        printf("Inserted %d\n", x);
    }
}

// DEQUEUE operation
int dequeue()
{
    // Check for queue underflow
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        int value = queue[front];
        front++;  // Remove front element
        return value;
    }
}

// PEEK operation
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];  // Return first element
    }
}

// DISPLAY operation
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// MAIN function
int main()
{
    int choice, value;
    int n;

    printf("Enter total size of queue (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Size exceeds limit\n");
        return 0;
    }

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1)
                    printf("Front value: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
