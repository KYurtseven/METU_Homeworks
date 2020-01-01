module WordTree(WordTree(Word, Subword, Root), emptyTree, getAllPaths, addWords, deleteWords, getWordsBeginWith) where

data WordTree = Word String | Subword String [WordTree] | Root [WordTree]

emptyTree :: WordTree
emptyTree = Root []
-- DO NOT MODIFY ABOVE

deleteWords :: WordTree -> [String] -> WordTree
deleteWords _ _ = Root []

addWords _ _ =  []


instance Show WordTree where
    show x = ""






getWordsBeginWith :: WordTree -> String -> [String]
getWordsBeginWith tree word = beginHelper tree word 0
getWordsBeginWith _ _ = []


beginHelper (Root []) word i = []
beginHelper tree word i =   if (i + 1 == lengthlist (getAllPaths tree)) then
                                if (isEqual ((recursiveBirlestir tree) !! i) word) then
                                    [(recursiveBirlestir tree !! i)]
                                else
                                    []
                            else
                                if (isEqual ((recursiveBirlestir tree) !! i) word) then
                                    [(recursiveBirlestir tree !! i)] ++ (beginHelper tree word (i + 1))
                                else
                                    beginHelper tree word (i + 1)

lengthlist [] = 0
lengthlist (x:xs) = 1 + lengthlist(xs)

ekle tepe [] = []
ekle tepe (x:xs) = (burasi tepe x) : (xs)

allleaves (Root []) = []
allleaves (Root (x:xs)) = allleaves x ++ p2 xs
allleaves (Subword node (x:xs)) = allleaves x ++ p2 xs
allleaves (Word w) = [w]

--verilen elemanin listenin o elemani ile esit mi diye kontrol ediyor
isEqual [] [] = True
isEqual _ [] = True
isEqual (x:xs) (y:ys) = ((x == y) && (isEqual xs ys))
isEqual _ _ = False

--tree'nin ilk elemani ile baslatiyor birlestirmeye
recursiveBirlestir :: WordTree -> [String]
recursiveBirlestir (Root []) = []
recursiveBirlestir tree = wordBirlestir tree 0

--[["he","ck"],["asd","abs"]] --> ["heck","abs"]
wordBirlestir :: WordTree -> Int -> [String]
wordBirlestir (Root []) i = []
wordBirlestir tree i = if (i + 1 == lengthlist (getAllPaths tree)) then
                        [tekStringYap "" ((getAllPaths tree) !! i)]
                       else
                        [tekStringYap "" ((getAllPaths tree) !! i )] ++ (wordBirlestir tree (i + 1)) 
    
--["he","ck"] ----> ["heck"]
tekStringYap :: [a] -> [[a]] -> [a]
tekStringYap s [] = []
tekStringYap s [x] = x
tekStringYap s (x:xs) = x ++ s ++ (tekStringYap s xs)



findPath wordX (Root []) = []
findPath wordX (Root (x:xs)) = findPath wordX x ++ p wordX xs

findPath wordX (Subword node (x:xs)) =  if (findPath wordX x == []) then
                                            if (p wordX xs == []) then
                                                []
                                            else
                                                ekle node (p wordX xs)
                                        else
                                            if (p wordX xs == []) then 
                                                ekle node (findPath wordX x)
                                            else 
                                                ekle node (findPath wordX x) ++ ekle node (p wordX xs)
        
findPath wordX (Word w) =   if (wordX == w) then 
                                [[w]]
                            else 
                                []

burasi tepe (x:xs) = tepe : (x:xs)

p wordX [] = []
p wordX (x:xs) = findPath wordX x ++ p wordX xs

p2 [] = []
p2 (x:xs) = allleaves x ++ p2 xs

getAllPaths :: WordTree -> [[String]]
getAllPaths (Root []) = []
getAllPaths (Root x) = make (Root x) (allleaves (Root x) ) []

make (Root y)   (x:xs)  previous = (make2 (Root y) x previous) : (make  (Root y) xs (make2 (Root y) x previous))
make _ _ previous = []

make2 (Root []) fChar previous = []
make2 (Root x ) fChar previous =    if count_element (findPath fChar (Root x)) == 1 then 
                                        head (findPath fChar (Root x))
                                    else 
                                        kontrol (findPath fChar (Root x)) previous
kontrol [] previous = []
kontrol (x:xs) [] = x
kontrol (x:xs) previous =   if (x > previous) then 
                                x
				            else 
                                kontrol xs previous

count_element [] = 0 
count_element (x:xs) = 1 + count_element xs


exampletree1 = Root [ Subword "He" [ Word "ck" , Subword "l" [ Word "lo" , Subword "p" [ Word "" , Subword "e" [ Word "d" , Word "r" ] , Word "ing" ] ] ] ]
exampletree2 = Root [ Subword "Ca" [ Subword "n" [ Word "" , Word "teen" ] , Word "ptain" , Subword "r" [ Word "" , Subword "r" [ Subword "ie" [ Word "d" , Word "s" ] , Word "y" ] ] ] , Subword "He" [ Word "ck" , Subword "l" [ Word "lo" , Subword "p" [ Word "" , Subword "e" [ Word "d" , Word "r" ] , Word "ing" ] ] ] ]
exampletree3 = Root [ Subword "F" [ Word "alse" , Subword "i" [ Word "asco" , Word "le" ] ] , Subword "Re" [ Word "aper" , Subword "po" [ Word "" , Word "sitory" ] ] , Subword "T" [ Subword "a" [ Subword "il" [ Word "" , Word "or" ] , Word "p" ] , Word "esla" ] ]