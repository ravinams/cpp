/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

 *******************************************************************************/
#ifndef MAP_SET
#define MAP_SET

#include<iostream>
using
std::ostream;
using
std::endl;
using
std::cout;
#include<string>
using
std::string;
#include<vector>
using
std::vector;
#include<utility>
using
std::pair;
#include<initializer_list>
using
std::initializer_list;
#include<algorithm>
using
std::sort;
using
std::lower_bound;
using
std::copy;
using
std::swap;
#include<sstream>
using
std::ostringstream;


//
// Node
//

template < typename K, typename V > struct Node {
    K
    first;
    V
    second;
    Node() = default;
    Node(K, V);
    bool
    operator<(const Node &) const;
    bool
    operator==(const Node &) const;

    friend
    ostream &
    operator<<(ostream & out, const Node & n) {
        out << n.first << ":" << n.second << endl;
        return
        out;
    }
};

template < typename K, typename V > Node < K, V >::Node(K key, V value) {
    first = key;
    second = value;
}

template < typename K, typename V >
bool Node < K, V >::operator<(const Node & n) const {
    return n.first > first;
}

template < typename K, typename V >
bool Node < K, V >::operator==(const Node & n) const {
    return first == n.first;
}

//
// MapSet
// 

template < typename K, typename V > class MapSet {
private:
    Node < K, V > *ary_;
    size_t
    last_;
    size_t
    capacity_;
    Node < K, V > *find_key(K);
    void
    grow();
public:
    MapSet(int sz = 2);
    MapSet(initializer_list < Node < K, V > >);
    MapSet(const MapSet &);
    MapSet
            operator=(MapSet);
    ~MapSet();
    size_t
    size();
    bool
    remove(K);
    bool
    add(Node < K, V >);
    Node < K, V > get(K);
    bool
    update(K, V);
    int
    compare(MapSet &);
    MapSet
    mapset_union(MapSet &);
    MapSet
    mapset_intersection(MapSet &);

    friend
    ostream &
    operator<<(ostream & out, const MapSet & ms) {
        for (int i = 0; i < ms.last_; i++) {
            out << (i ==
                    0 ? "" : ", ") << ms.ary_[i].first << ":" << ms.ary_[i].
                    second;
        }
        return out;

    }
};

template < typename K, typename V > MapSet < K, V >::MapSet(int capacity) {
    capacity_ = capacity;
    last_ = 0;
    Node < K, V > *ary_ = new Node < K, V >[capacity];


}

template < typename K, typename V >
MapSet < K, V >::MapSet(initializer_list < Node < K, V > >il) {
    
    cout.flush();
    
    cout<<" initializer_list "<<endl ;
    size_t
    indx = 0;
    capacity_ = il.size();
    //ary_ = new char[sz_];
    
     cout<<" Before new  "<<endl ;
     
    Node < K, V > *ary_ = new Node < K, V >[capacity_];
    
     cout<<" After new  "<<endl ;
     
    typename initializer_list < Node <K,V >>::iterator it;
    
      cout<<" After iterator  "<<endl ;
      
    for (it = il.begin(); it != il.end(); ++it) {
        cout << *it << endl;
        cout<<"calling add method"<<endl ;
        add(*it);
    }



    //grow();
    // for(int i =0; i < 4; i++){
    //     ary_[i]= e;
    //     indx++;
    //     cout<<e<<endl;
    //     last_ = indx;
    // }
    // ary_[indx]= e;
    //indx++;
    //last_ = indx;





}

template < typename K, typename V >
MapSet < K, V >::MapSet(const MapSet & ms) {

}

// copy and swap

template < typename K, typename V >
MapSet < K, V > MapSet < K, V >::operator=(MapSet < K, V > ms) {
    std::swap(*this, ms);
    return *this;
}

template < typename K, typename V > MapSet < K, V >::~MapSet() {

}

template < typename K, typename V > size_t MapSet < K, V >::size() {
    return last_;
}

template < typename K, typename V > void MapSet <K,V >::grow() {
    
    if (capacity_ == 0) {
        Node < K, V > *new_ary = new Node < K, V >[1] {
        };
        capacity_ = 1;
        last_ = 0;
        ary_ = new_ary;

    } else {

        Node < K, V > *new_ary = new Node < K, V >[capacity_ * 2] {
        };
        copy(ary_, ary_ + capacity_, new_ary);
        capacity_ *= 2;
        std::swap(new_ary, ary_);
        delete[]new_ary;
    }
}

template < typename K, typename V >
Node < K, V > *MapSet < K, V >::find_key(K key) {
    //   auto
    //     point = lower_bound (ary_, ary_ + last_, key);
    //   //if(point == ary_+ last_){
    //   // return nullptr;
    //   // }


    // TEMP find code
    for (int i = 0; i < last_; i++) {
        if (ary_[i].first >= key)
            return &ary_[i];
    }
    return nullptr;
}

template < typename K, typename V >
bool MapSet < K, V >::add(Node < K, V > n) {
    cout.flush() ;
    cout << "add () ";
    if (last_ == 0) // first element addition
    {
        ary_[last_++] = n;

    } else if (n < ary_[0]) // first element is greater than new element
    {
        if (last_ == capacity_)
            grow();

        for (int i = last_ - 1; i >= 0; i) {
            ary_[i + 1] = ary_[i];
        }
        ary_[0] = n;

        last_++;

    } else if (ary_[last_ - 1] < n) // last element is less than new element
    {
        if (last_ == capacity_)
            grow();

        ary_[last_++] = n;

    } else // element some where may be in middle 
    {
        Node < K, V > *foundNode = find_key(n.first);
        if (foundNode == nullptr) {
            if (last_ == capacity_)
                grow();

            ary_[last_++] = n;
        } else if (foundNode->first == n.first) // element with key alerady exists 
        {
            return false;
        } else // that means .. found Node is greater then new node 
        {
            if (last_ == capacity_)
                grow();


            Node < K, V > *new_ary = new Node < K, V >[capacity_] ; 
            // first add .. lesser elements
            int indx = 0;
            for (; indx < last_; indx++) {
                if (ary_[indx] < n)
                    new_ary[indx] = ary_[indx];
            }

            // now add current elements
            new_ary[indx++] = n;
            // now add higher elements

            for (; indx < last_; indx++) {
                new_ary[indx] = ary_[indx - 1];
            }



            std::swap(new_ary, ary_);
            delete[]new_ary;

            last_++;
        }
        return true;
    }


    // auto found = find_key(n.first);
    // int index = std::distance( ary_, found );
    // //cout<<"index"<<index<<endl;
    // grow();
    // Node<K,V>* ary_2 = new Node<K,V>[capacity_];

    // // for(int i = 1; i < index; i++){
    // copy(ary_, ary_ + index, ary_2);
    // // }
    // // ary_2[index] = n;
    // copy(ary_ + index, ary_ +last_, ary_2 +index +1);
    // ary_2[index] = n;

    // std::swap(ary_, ary_2);
    // delete [] ary_2;
    // //last_++;
    // // cout<<"hi"<<endl;
    // return true;
    //if(found != nullptr){
    //return false;
    // }
    // else{
    // copy(ary_, ary_ + index, ary_2);
    // ary_2[index] = n;
    // copy(ary_ + index+1, ary_ + last_, ary_2);
    // swap(ary_, ary_2);
    // last_ = last_+1;
    // delete [] ary_2;
    // cout<<"hi"<<endl;
    // return true;

    //}
    //if(found-> first == n.first){
    //return false;
    // }
    // else{
    // copy(ary_, (ary_ + index -1), ary_2);
    // ary_2[index] = n;
    // copy((ary_ + index + 1), (ary_ + last_) , ary_2);
    // swap(ary_, ary_2);
    // delete [] ary_2;
    // return true;

    //  }

}

template < typename K, typename V > bool MapSet < K, V >::remove(K key) {

}

template < typename K, typename V > Node < K, V > MapSet < K, V >::get(K key) {
    for (auto i = 0; i < last_; i++) {
        if (ary_[i].first == key) {
            return ary_[i];
        }
    }
}

template < typename K, typename V >
bool MapSet < K, V >::update(K key, V value) {

}

template < typename K, typename V > int
MapSet <
K,
V >::compare(MapSet & ms) {

}

template < typename K, typename V >
MapSet < K, V > MapSet < K, V >::mapset_union(MapSet < K, V > &ms) {

}

template < typename K, typename V >
MapSet < K, V > MapSet < K, V >::mapset_intersection(MapSet < K, V > &ms) {

}

#endif
