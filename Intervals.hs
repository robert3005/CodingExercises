module Intervals where

import Data.List
import Data.Function

{-
	You are given list of intervals where first number is starting time and second is end time
	Your task is to sort them and merge any overlapping so you will obtain flat list of non-overlapping intervals
-}

orderIntervals :: (Num a, Ord a) => [(a,a)] -> [(a,a)]
orderIntervals plan = reverse $ foldl' flattenIntervals [head orderedPlan] orderedPlan
	where
		orderedPlan = sortBy (compare `on` fst) plan

flattenIntervals :: (Num a, Ord a) => [(a, a)] -> (a, a) -> [(a, a)]
flattenIntervals currentInts newInt
	| overlaps lastInt newInt = merge lastInt newInt : tail currentInts
	| otherwise = newInt : currentInts
	where
		lastInt = head currentInts

overlaps :: (Num a, Ord a) => (a,a) -> (a,a) -> Bool
overlaps (s1,t1) (s2,t2) = or [s2 - s1 <= 0, s2 - t1 <= 0]

merge :: (Num a, Ord a) => (a,a) -> (a,a) -> (a,a)
merge (s1,t1) (s2,t2) = (s1, (max t1 t2))