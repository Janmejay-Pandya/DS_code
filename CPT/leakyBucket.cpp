#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

class Packet
{
    // Packet class to simulate data packets.
    int id, size;

public:
    Packet(int id, int size)
    {
        // Constructor to initialize packets.
        this->id = id;
        this->size = size;
    }
    int getSize() const
    {
        return this->size;
    }
    void reduceSize(int amount)
    {
        this->size -= amount;
    }
    int getId() const
    {
        return this->id;
    }
};

class LeakyBucket
{
    // Leaky Bucket class to simulate leaky bucket algorithm.
    int leakRate, bufferSizeLimit, currBufferSize;
    queue<Packet> buffer;

public:
    LeakyBucket(int leakRate, int size)
    {
        // Constructor to initialize leak rate, and maximum buffer size available.
        this->leakRate = leakRate;
        this->bufferSizeLimit = size;
        this->currBufferSize = 0;
    }
    void addPacket(const Packet &newPacket)
    {
        // Function to add new packets at the end of the buffer.
        if (currBufferSize + newPacket.getSize() > bufferSizeLimit)
        {
            // If the packet cannot fit in the buffer, then reject the packet.
            cout << "Bucket is full. Packet with id = " << newPacket.getId() << " rejected." << endl;
            return;
        }
        // Add packet to the buffer.
        buffer.push(newPacket);
        // Update current buffer size.
        currBufferSize += newPacket.getSize();
        // Print out the appropriate message.
        cout << "Packet with id = " << newPacket.getId() << " added to bucket." << endl;
    }
    void transmit()
    {
        // Function to transmit packets. Called at each clock tick.
        if (buffer.empty())
        {
            // Check if there is a packet in the buffer.
            cout << "No packets in the bucket." << endl;
            return;
        }
        // Initialize n to the leak rate.
        int n = leakRate;
        while (!buffer.empty())
        {
            Packet &topPacket = buffer.front();
            int topPacketSize = topPacket.getSize();

            // Check if the packet can be fully transmitted or partially transmitted.
            if (topPacketSize <= n)
            {
                // Packet can be fully transmitted
                n -= topPacketSize;
                currBufferSize -= topPacketSize;
                cout << "Packet with id = " << topPacket.getId() << " fully transmitted." << endl;
                buffer.pop();
            }
            else
            {
                // Packet is partially transmitted
                topPacket.reduceSize(n);
                currBufferSize -= n;
                cout << "Packet with id = " << topPacket.getId() << " partially transmitted. Remaining size: " << topPacket.getSize() << endl;
                break;
            }
        }
    }
};

int main()
{
    // Create bucket on the stack instead of using dynamic allocation.
    LeakyBucket bucket(1000, 10000);

    // Add packets to the bucket.
    bucket.addPacket(Packet(1, 200));
    bucket.addPacket(Packet(2, 500));
    bucket.addPacket(Packet(3, 400));
    bucket.addPacket(Packet(4, 500));
    bucket.addPacket(Packet(5, 200));

    // Simulate the ticking process for transmission.
    while (true)
    {
        bucket.transmit();
        cout << "Waiting for next tick." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for 1 second between each tick.
    }

    return 0;
}
