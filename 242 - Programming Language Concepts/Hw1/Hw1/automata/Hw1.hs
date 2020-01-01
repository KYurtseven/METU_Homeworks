module Hw1 (next) where -- DO NOT CHANGE THIS

next :: [[String]] -> [[String]]
-- IMPLEMENT NEXT FUNCTION HERE --

next list = ifelseCheck list list 0 0

len  [] = 0
len (x:xs) = 1 + len(xs)

ifelseCheck list newlist i j =  let   
                                    canStayAlive     = (((list !! i) !! j) == "B" && ((countBs list i j) == 3 || (countBs list i j) == 2 ))
                                    canDie           = (((list !! i) !! j) == "B" && ((countBs list i j) <  2 || (countBs list i j) >  3 ))
                                    canResurrect     = ((list !! i) !! j) == "W" && ((countBs list i j) == 3)
                                    isLastRow        = ((j + 1) == len (list !! 0))
                                    isLastColoumn    = ((i + 1) == len list)
                                    case1            = ifelseCheck list (changeRow newlist i j "B") (i + 1) 0
                                    case2            = ifelseCheck list (changeRow newlist i j "B") i (j + 1)
                                    case3            = ifelseCheck list (changeRow newlist i j "W") (i + 1) 0
                                    case4            = ifelseCheck list (changeRow newlist i j "W") i (j + 1)
                                in
                                    if canStayAlive then
        						        if isLastRow then
                                            if isLastColoumn then
                                                newlist
                                            else
                                                case1
                                        else
                                            case2
                                    else if canDie then
                                        if isLastRow then
                                            if isLastColoumn then
                                                changeRow newlist i j "W"
                                            else
                                                case3
                                        else
                                            case4
                                    else if canResurrect then
                                        if isLastRow then
                                            if isLastColoumn then
                                                changeRow newlist i j "B"
                                            else
                                                case1
                                        else
                                            case2
                                    else
                                        if isLastRow then
                                            if isLastColoumn then
                                                newlist
                                            else
                                                case3
                                        else
                                            case4
                                    
changeRow list i j char =   let
                                isLastRow           = ((i + 1) == len list)
                                isFirstRow          = (i == 0)
                                previousPartofNList = [changeColumn list i j char]
                                nextPartofNList     = (drop (i + 1) list)
                                takeNList           = (take i list)
                            in
                                if isLastRow then
                                    if isFirstRow then
                                        previousPartofNList
                                    else
                                        takeNList ++ previousPartofNList
                                else if isFirstRow then
                                    previousPartofNList ++ nextPartofNList
                                else
                                    takeNList ++ previousPartofNList ++ nextPartofNList

changeColumn list i j char =    let
                                    isLastColoumn   = ((j + 1) == len (list !! 0))
                                    isFirstColoumn  = (j == 0)
                                    nextPartofList  = (drop (j + 1) (list  !! i))
                                    takeList        = (take j (list  !! i))
                                in
                                    if isLastColoumn then
                                        if isFirstColoumn then
                                            [char]
                                        else
                                            takeList ++ [char]
                                    else if isFirstColoumn then
                                        [char] ++ nextPartofList
                                    else
                                        takeList ++ [char] ++ nextPartofList

--Counts alive bacteria Cells near the given location
countBs list i j = len [x*y | x <- [i-1, i, i+1], y <- [j-1, j, j+1], x >= 0, y >= 0, [x,y] /= [i,j], x < len list , y < len (list !! 0), ((list !! x) !! y) == "B"]



-- DO NOT CHANGE CODE BELOW THIS LINE! --
createFile fileName = writeFile fileName ""

writeSteps filename grid n = do
                    createFile filename
                    writeStepsHelper filename grid n n
    where writeStepsHelper filename grid n all = if n == 0 then putStrLn ((show all) ++ " steps are succesfully written to \'" ++ filename ++ "\'") else do
                                    appendFile filename ((show (next grid)) ++ "\n")
                                    writeStepsHelper filename (next grid) (n-1) all




   
