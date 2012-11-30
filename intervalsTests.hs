module IntervalsTests where

import Intervals
import Test.Hspec
import Test.QuickCheck
import Test.HUnit

instance Arbitrary (Int, Int) where
	arbitrary = liftM2 (,) arbitrary arbitrary

main :: IO ()
main = hspec spec

spec :: Spec
spec =
	describe "auxiliary functions tests" $ do
		prop "overlaps is true only for overlapping intervals" $ (\x y -> overlaps x y)
