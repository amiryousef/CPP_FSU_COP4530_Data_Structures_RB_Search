/*
   rbsearch.h
   02/19/12
   hw2 - COP4530 - Fall12
   Amir Yousef - ay10d - yousef
   Generic binary search algorithm for random access iterators
   Recursive implementations
*/

#ifndef _RBSEARCH_H
#define _RBSEARCH_H

#include <compare.h>

namespace alt
{
  template <class I, typename T, class P>
  I g_lower_bound (I low, I hih, const T& val, const P& cmp)
  // pre:    I is a random access iterator (operator [] and "pointer" arithmetic)
  //         I has ValueType T
  //         low + n = hih for some n >= 0
  //         low[0] ... low[n-1] are in non-decreasing order using cmp
  // post:   no state is changed
  // return: itr = lower bound location in range, that is:
  //         itr = low + i, where low[i-1] < val <= low[i] or
  //         itr = hih if no such i exists
  {
    // base case
    if (low == hih)
      return low;
    else
    {
      I mid = low + ((hih - low) >> 1);

      if (cmp(*mid, val))
        return alt::g_lower_bound(++mid, hih, val, cmp);
      else
        return alt::g_lower_bound(low, mid, val, cmp);
    }
  }

  template <class I, typename T, class P>
  I g_upper_bound(I low, I hih, const T& val, const P& cmp)
  // pre:    I is a random access iterator (operator [] and "pointer" arithmetic)
  //         I has ValueType T
  //         low + n = hih for some n >= 0
  //         low[0] ... low[n-1] are in non-decreasing order using cmp
  // post:   no state is changed
  // return: itr =  low + i, where low[i-1] <= val < low[i]; or
  //         itr = hih if no such i exists
  {
    // base case
    if (low == hih)
      return low;
    else
    {
      I mid = low + ((hih - low) >> 1);

      if (cmp(val, *mid))
        return alt::g_upper_bound(low, mid, val, cmp);
      else
        return alt::g_upper_bound(++mid, hih, val, cmp);
    }
  }

  template <class I, typename T, class P>
  bool g_binary_search (I low, I hih, const T& val, const P& cmp)
  // pre:    I is a random access iterator (operator [] and "pointer" arithmetic)
  //         I has ValueType T
  //         low + n = hih for some n >= 0
  //         low[0] ... low[n-1] are in non-decreasing order using cmp
  // post:   no state is changed
  // return: true if found, false if not found
  {
    I lb = alt::g_lower_bound(low, hih, val, cmp);
    if (lb != hih)
    {
      if (val == *lb)
      {
        return 1;
      }
    }
    return 0;
  }

  template <class I, typename T>
  I g_lower_bound (I low, I hih, const T& val)
  {
    fsu::LessThan<T> cmp;
    return alt::g_lower_bound(low, hih, val, cmp);
  }

  template <class I, typename T>
  I g_upper_bound (I low, I hih, const T& val)
  {
    fsu::LessThan<T> cmp;
    return alt::g_upper_bound(low, hih, val, cmp);
  }

  template <class I, typename T>
  bool g_binary_search (I low, I hih, const T& val)
  {
    fsu::LessThan<T> cmp;
    return alt::g_binary_search(low, hih, val, cmp);
  }
}

#endif
