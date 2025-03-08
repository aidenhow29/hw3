#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

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
  T const & top() const; //done

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
  bool empty() const; //done

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const; //done

private:
  /// Add whatever helper functions and data members you need below

int numChildren;
PComparator comparator;
std::vector<T> vec;

};

// Add implementation of member functions here


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

    throw std::underflow_error("error");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return vec[0];

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

    throw std::underflow_error("error");
  }

  PComparator compare;
  vec[0] = vec.back();
  vec.pop_back();

  int loc = 0; //root

  while(true){
    int bestChild = -1;
    int firstChild = numChildren * loc + 1;

    for(int i = 0; i < numChildren; i++){
      int childIndex = firstChild + i;
      if(childIndex < vec.size()){
        if(bestChild == -1 || compare(vec[childIndex], vec[bestChild])){
          bestChild = childIndex;
        }
      }
    }

    if(bestChild == -1 || compare(vec[loc], vec[bestChild])){
      break;
    }

    std::swap(vec[loc], vec[bestChild]);
    loc = bestChild;
  }
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  numChildren = m;
  comparator = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return vec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return vec.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
 vec.push_back(item);
 int loc = vec.size()-1;
 PComparator compare;

 while(loc > 0)
 { 
  
  int parent = (loc-1) / numChildren;

    if(compare(vec[loc], vec[parent]))  
      {
          std::swap(vec[loc], vec[parent]);
          loc = parent;
      }
      else
      {
          break;
      }
    }
}



#endif

