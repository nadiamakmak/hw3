#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  void heapify(int idx);
  void trickleUp(int loc);
  std::vector<T> stuff;
  int aryness;
  PComparator pred;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  aryness = m;
  pred = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  stuff.push_back(item);
  trickleUp(stuff.size()-1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return stuff.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(stuff[0], stuff[stuff.size()-1]);
  stuff.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return stuff.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return stuff.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx){
  unsigned int betterChild = (2*idx)+1; //set best child to left child

  if(betterChild >= stuff.size()){ //if this child doesn't exist (aka we're at a leaf node)
    return; //end
  }

  if((betterChild+1)<stuff.size()){ //if there is a right child
    int right = betterChild+1;
    if(pred(stuff[right], stuff[betterChild])){ //if the right child is better than the left child
      betterChild = right; //the right child becomes to best child
    }
  }

  if(pred(stuff[betterChild], stuff[idx])){ //if the best child is better than the parent
    std::swap(stuff[betterChild], stuff[idx]); //swap the child and the parent
    heapify(betterChild); //heapify the bestChild index 
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc){
  int parent = (loc-1)/2; //get parent id
  
  if(!pred(stuff[loc], stuff[parent])){ //if not better than the parent, right place, return
    return;
  }
  else{
    std::swap(stuff[loc], stuff[parent]); //if better, swap and trickle up from the new location
    trickleUp(parent);
  }

}


#endif

