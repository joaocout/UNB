--moves the minimum of a list to the first position
minimum_first :: [Int] -> [Int]
minimum_first list =
    if(length list < 2 || head list == minimum list) then list
    else if(last list == minimum list) then [last list] ++ init(tail list) ++ [head list]
    else minimum_first (init list) ++ [last list]

--recursive bubble sort
bsort :: [Int] -> [Int]
bsort list =
    if(length list < 2) then list
    else if(head list == minimum list) then [head list] ++ bsort (tail list)
    else [head (minimum_first list)] ++ bsort (tail (minimum_first list))