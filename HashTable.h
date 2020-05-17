#ifndef HASHTABLE_H
#define HASHTABLE_H

enum CollisionStrategy {LINEAR, QUADRATIC, DOUBLE};

class HashTable
{
    public:
        HashTable( const int tableSize, const CollisionStrategy option );
        virtual ~HashTable();
        bool insert( const int item);
        bool remove( const int item);
        bool search( const int item, int& numOfProbes);
        void display();
        void analyze( double& numSuccProbes, double& numUnsuccProbes );

    protected:

    private:
        int tSize;
        CollisionStrategy collisionOption;
        int itemCounter;
        int* htable;
};

#endif // HASHTABLE_H
