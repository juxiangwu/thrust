/*
 *  Copyright 2008-2010 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/detail/type_traits.h>
#include <thrust/range/iterator_range.h>
#include <thrust/range/detail/iterator.h>
#include <thrust/iterator/permutation_iterator.h>

namespace thrust
{

namespace experimental
{

namespace range
{

namespace detail
{


template<typename OutputRange>
  struct gather_result
    : thrust::detail::identity_<
        iterator_range<typename range_iterator<OutputRange>::type>
      >
{};


template<typename SinglePassRange, typename RandomAccessRange>
  struct lazy_gather_result
    : thrust::detail::identity_<
        iterator_range<
          permutation_iterator<
            typename range_iterator<RandomAccessRange>::type,
            typename range_iterator<SinglePassRange>::type
          >
        >
      >
{};


} // end detail

} // end range

} // end experimental

} // end thrust

