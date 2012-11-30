import Control.Monad
import Data.List
import Data.Char

permute [] = [[]]
permute xs = do
    x <- xs
    p <- permute (xs \\ [x])
    return (x : p)

perm :: Eq a => [a] -> [[a]]
perm [] = [[]]
perm xs = concatMap (\x -> map (x:) (perm (xs\\[x])) ) xs

powerset :: [a] -> [[a]]
powerset [] = [[]]
powerset (x:xs) = powerset xs ++ map (x:) (powerset xs)

pwrset :: [a] -> [[a]]
pwrset = filterM (const [False, True])

phoneAlphabet :: Int -> [String]
phoneAlphabet number = foldl (\x y -> concatMap (\el -> map (\d -> filter (\md -> not $ isSpace md) $ el ++ [d] ) (digitToChars $ (ord y - ord '0') - 1)) x) [[]] $ show number

digitToChars :: Int -> [Char]
digitToChars x = keyboardMap !! x
                where
                    keyboardMap = [" ", "abc", "def", "ghi", "jkl", "mno", "prs", "tuv", "wxyz"]
