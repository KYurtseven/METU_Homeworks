module Hw1 (next) where -- DO NOT CHANGE THIS

next :: [[String]] -> [[String]]
-- IMPLEMENT NEXT FUNCTION HERE --
next xs = func xs xs 0 0

func xs ks i j = 	if (((xs !! i) !! j) == "B" && ((adjoint xs i j) == 3 || (adjoint xs i j) == 2)) then
						if (j + 1) == length (xs !! 0) then
							if (i + 1) == length xs then
								changelist ks i j "B"
							else
								func xs (changelist ks i j "B") (iteratethis i) 0
						else
							func xs (changelist ks i j "B") i (iteratethis j)
					else if (((xs !! i) !! j) == "B" && ((adjoint xs i j) /= 3 && (adjoint xs i j) /= 2)) then
						if (j + 1) == length (xs !! 0) then
							if (i + 1) == length xs then
								changelist ks i j "W"
							else
								func xs (changelist ks i j "W") (iteratethis i) 0
						else
							func xs (changelist ks i j "W") i (iteratethis j)
					else if (((xs !! i) !! j) == "W" && (adjoint xs i j) == 3) then
						if (j + 1) == length (xs !! 0) then
							if (i + 1) == length xs then
								changelist ks i j "B"
							else
								func xs (changelist ks i j "B") (iteratethis i) 0
						else
							func xs (changelist ks i j "B") i (iteratethis j)
					else
						if (j + 1) == length (xs !! 0) then
							if (i + 1) == length xs then
								changelist ks i j "W"
							else
								func xs (changelist ks i j "W") (iteratethis i) 0
						else
							func xs (changelist ks i j "W") i (iteratethis j)

lengthlist [] = 0
lengthlist (x:xs) = 1 + lengthlist(xs)

adjoint xs i j = length [x*y | x <- [i-1, i, i+1], y <- [j-1, j, j+1], [x,y] /= [i,j], x >= 0, y >= 0, x < lengthlist xs , y < lengthlist (xs !! 0), ((xs !! x) !! y) == "B"]

iteratethis x = x+1

changelist :: [[String]] -> Int -> Int -> String -> [[String]]
changelist xs i j a = 	if (((i+1) == length xs) && (i == 0)) then
							[changecolumn xs i j a]
						else if (i + 1) == length xs then
							(take i xs) ++ [changecolumn xs i j a]
						else if (i == 0) then
							[changecolumn xs i j a] ++ (drop (i+1) xs)
						else
							(take i xs) ++ [changecolumn xs i j a] ++ (drop (i+1) xs)

changecolumn :: [[String]] -> Int -> Int -> String -> [String]
changecolumn xs i j a = 	
							if (((j+1) == length (xs !! 0)) && (j == 0)) then
								[a]
							else if (j + 1) == length (xs !! 0) then
								(take j (xs!!i)) ++ [a]
							else if (j == 0) then
								[a] ++ (drop (j+1) (xs!!i))
							else
								(take j (xs!!i)) ++ [a] ++ (drop (j+1) (xs!!i))

-- DO NOT CHANGE CODE BELOW THIS LINE! --
createFile fileName = writeFile fileName ""

writeSteps filename grid n = do
                    createFile filename
                    writeStepsHelper filename grid n n
    where writeStepsHelper filename grid n all = if n == 0 then putStrLn ((show all) ++ " steps are succesfully written to \'" ++ filename ++ "\'") else do
                                    appendFile filename ((show (next grid)) ++ "\n")
                                    writeStepsHelper filename (next grid) (n-1) all