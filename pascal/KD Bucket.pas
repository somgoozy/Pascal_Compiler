program project2(input, output);

type
    KDBucket = array of array of real;
    KDNodeRef = ^KDNode;
    KDNode = record
        isLeaf : boolean;
        leftChild, rightChild : KDNodeRef;
        dimension : integer;
        median : real;
        leafBucket : KDBucket;
    end;

var
    sourceFile : text;
    n, p, i, j: integer;
    dataArray : array of array of real;
    rootData : KDNode;
    probe : array [1..4] of real;
    probeResults : KDBucket;



function discriminate (dataArray : KDBucket; size : integer) : integer;

var
    minMax : array [1..3] of array [1..4]  of real;
    i, j : integer;

begin {discriminate}
    for i := 1 to 4 do
        begin
        minMax [1, i] := dataArray [1, i];
        minMax [2, i] := dataArray [1, i];
        end;
    for i := 1 to size do
        for j := 1 to 4 do
            begin
            if (dataArray [i, j] < minMax [1, j]) then
                minMax [1, j] := dataArray [i, j]
            else if (dataArray [i, j] > minMax [2, j]) then
                minMax [2, j] := dataArray [i, j];
            end;
    for i := 1 to 4 do
        minMax [3, i] := minMax [2, i] - dataArray [1, i];
    if (((minMax [3, 1] > minMax [3,2]) and (minMax [3, 1] > minMax [3,3]))
        and (minMax [3, 1] > minMax [3,4])) then
        discriminate := 1
    else if ((minMax [3, 2] > minMax [3,3]) and
        (minMax [3, 2] > minMax [3,4])) then
        discriminate := 2
    else if (minMax [3, 3] > minMax [3,4]) then
        discriminate := 3
    else
        discriminate := 4;
end; {discriminate}



function partition (var dataArray : KDBucket; min, max, dimension,
    pivotPoint : integer) : integer;

var
    pivotPointValue, temp : real;
    i, j : integer;

begin {partition}
    pivotPointValue := dataArray [pivotPoint, dimension];
    for i:= 1 to 4 do
    begin
        temp := dataArray [pivotPoint, i];
        dataArray [pivotPoint, i] := dataArray [max, i];
        dataArray [max, i] := temp;
    end;
    for i := min to max do
        if (dataArray [i, dimension] < pivotPointValue) then
            begin
                for j:= 1 to 4 do
                begin
                    temp := dataArray [min, j];
                    dataArray [min, j] := dataArray [i, j];
                    dataArray [i, j] := temp;
                end;
                min := min + 1;
            end;
    for i:= 1 to 4 do
    begin
        temp := dataArray [min, i];
        dataArray [min, i] := dataArray [max, i];
        dataArray [max, i] := temp;
    end;
    partition := min;
end; {partition}



function select (var dataArray : KDBucket; min, max, k, dimension
    : integer) : real;

var
    pivotIndex : integer;

begin {select}
    if (min = max) then
        select := dataArray [min, dimension]
    else
    begin
        pivotIndex := (min + max) div 2;
        pivotIndex := partition (dataArray, min, max, dimension, pivotIndex);
        if (k = pivotIndex) then
            select := dataArray [k, dimension]
        else if (k < pivotIndex) then
            select := select (dataArray, min, pivotIndex - 1, k, dimension)
        else
            select := select (dataArray, pivotIndex + 1, max, k, dimension);
    end;
end; {select}



function branch (var dataArray : KDBucket; n: integer) : KDNodeRef;

var
    leftData, rightData : KDBucket;
    i, j : integer;

begin {branch}
    new(branch);
    if (n > 10) then
    begin
        branch^.isLeaf := FALSE;
        branch^.dimension := discriminate (dataArray, n);
        if ((n mod 2) = 0) then
        begin
            branch^.median := select (dataArray, 1, n, (n div 2),
                branch^.dimension);
            branch^.median := (branch^.median + select (dataArray, 1, n,
                ((n div 2) + 1), branch^.dimension) / 2);
            setlength (leftData, (n div 2));
            for i := 1 to (n div 2) do
                setLength (leftData [i], 4);
            setlength (rightData, (n div 2));       
            for i := 1 to (n div 2) do
                setLength (rightData [i], 4);
            for i := 1 to (n div 2) do
                for j := 1 to 4 do
                    leftData [i, j] := dataArray [i, j];
            for i := 1 to (n div 2) do
                for j := 1 to 4 do
                    rightData [i, j] := dataArray [i + (n div 2), j];
            branch^.leftChild := branch (leftData, (n div 2));
            branch^.rightChild := branch (rightData, (n div 2));
        end
        else
        begin
            branch^.median := select (dataArray, 1, n, ((n div 2) + 1),
                branch^.dimension);
            setlength (leftData, ((n div 2) + 1));
            for i := 1 to ((n div 2) + 1) do
                setLength (leftData [i], 4);
            setlength (rightData, (n div 2));       
            for i := 1 to (n div 2) do
                setLength (rightData [i], 4);
            for i := 1 to ((n div 2) + 1) do
                for j := 1 to 4 do
                    leftData [i, j] := dataArray [i, j];
            for i := 1 to (n div 2) do
                for j := 1 to 4 do
                    rightData [i, j] := dataArray [i + (n div 2), j];
            branch^.leftChild := branch (leftData, ((n div 2) + 1));
            branch^.rightChild := branch (rightData, (n div 2));
        end;
    end
    else
    begin
        branch^.isLeaf := TRUE;
        branch^.leafBucket := dataArray;
    end;
end; {branch}



function searchKDTree (root : KDNode; var probe : array of real) : KDBucket;

begin
    if (root.isLeaf) then
        searchKDTree := root.leafBucket
    else if (root.median < probe [root.dimension]) then
        searchKDTree := searchKDTree (root.rightChild^, probe)
    else
        searchKDTree := searchKDTree(root.leftChild^, probe);
end; {searchKDTree}



begin {main}
    assign (sourceFile, 'asg.pascal.data');
    reset (sourceFile);
    readln (sourceFile, n);
    setLength (dataArray, n);
    for i := 1 to n do
        setLength (dataArray [i], 4);
    if (n >= 0) then
        if (n >= 1) then
        begin
            for i := 1 to n do
                readln (sourceFile, dataArray [i, 1], dataArray [i, 2],
                    dataArray [i, 3], dataArray [i, 4]);
            rootData := branch (dataArray, n)^;
            readln (sourceFile, p);
            if (p > 1) then
            begin
                for i := 1 to p do
                begin
                    readln (sourceFile, probe [1], probe [2], probe [3], probe [4]);
                    writeln ('The nodes in this bucket are:');
                    probeResults := searchKDTree (rootData, probe);
                    for j := 1 to (Length (probeResults)) do
                    begin
                        write (probeResults [j, 1] : 8 : 1);
                        write (', ');
                        write (probeResults [j, 2] : 8 : 1);
                        write (', ');
                        write (probeResults [j, 3] : 8 : 1);
                        write (', ');
                        writeln (probeResults [j, 4] : 8 : 1);

                    end;
                end;
            end
            else
                writeln
                    ('Your p is less than 1. There is nothing to compare.');
        end
        else begin
            writeln ('Your tree is empty. There is nothing to compare to.');
        end
    else
        writeln ('Expecting a positive value for n.');
end. {main}