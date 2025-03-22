tet2.Code Question 2
Imagine you're a seller on Amazon,
specializing in eco - frlendly home products.
Each ofyour items israted bycustomers
based on its quality and environmental
impact.
The overall qualityScore ofyour products is
determinedbythemaximumpossiblesum
of consecutive ratings.
Toimprove thequalityScoreof your
products and attractmore customers, you
are given with aninteger impactFactor and
thefollcwing twostrategies :
1.Amplify Ratings : Select a contiguous
segment of ratings andamplify them bymultiplyingeachratinginthatrangebyImpactFactor,
2.Adjust Ratings : Select a contiguoussegment of ratings and adjust thembydividing each rating in thatrange byimpactFactor.
possible qualityScore for your eco - friendlyYour taskisto determine the maximum
products after applying exactly one of these
Your task is to determine themaximum
possible qualityScore for your eco - friendly
products after applying exactly one of these
strategies.
Note:When applying the second strategy
i.e., Adjust Ratings : For dividing positive
ratings, use the floor value of the division
result and for dividingnegative ratings, use
the ceilingvalue of the divisionresult.
Example : Givenratings = [4, -5, 5, -7, 1], and
impactFactor = 2.
If we choose to apply the second strategy
with segment[2, 5](Assuming1 - based
    indexing)then, modified ratings.[4, ceil - 5 /
    2), floor(5 / 2）, ceil（ - 7 / 2）, floor（1 / 2）] = [4, -2,
        2, -3, 01.
        Note that the ceil(-7 / 2) = -3 and floor(5 / 2)
        = 2.
        Given an array of ratings of size n and an
        integer impactFactor, determine the
        maximum possible qualityScore i.e.,
        maximum possible sum of consecutive
        the strategies to modify the ratings.ratings by optimally selecting exactly one of
        Example

        Example
        n = 5
        ratings = [5, -3, -3, 2, 4]
        impactFactor = 3
        Let's tryboth the strategieswith different
        contiguous ranges toget themaximum
        qualityScore :
Segment
(1 - basedModified
    Strategyindexing)Ratingsquality.
    [1, [5 * 2, -3, 10
    1] - 3, 2, 4] =
    [10, -3,
    -3, 2, 4]
    [2, [5,
    3]ceil(-3 / 2),
    ceil(-3 / 2),
    2, 4] = [5,
    -1, -1, 2,
    4]
    [4, [5, -3, -3, 12
    5]2 * 2, 4 * 2]
    = [5, -3,
    -3, 4, 8]

    If we perform the first strategy on the
    eftsubsegment[4.5](1 - based Indexing).we
    get the ratings = [5. - 3, 3, 4, 8]with a
    qualityScoreof12, whichisthemaximum
    qualityScore.
    Hence, the answer is12.
    Function Description
    Complete the function
    calculateMaxQualityScorein the editor
    below.
    calculateMaxQualityScorehasthefollowing
    parameters :
intimpactFactor:thevalue used in the
strategiesto amplify or adjustratings.
int ratings[n] : an array representing the
ratings of eco - friendly product
Returns
long : themaximumpossible qualityScore
of your eco - friendly products after applying
exactlty one of the strategies.
Constraints
·1sn≤2 * 105
1≤impactFactor≤104
- 105≤ratingsti]≤105

Input Format For Custom Testing
Sample Case O
Sample Input For Custom Testing
STDINFUNCTION
impactFactor = 1
ratings[] size n
2ratings = [-2, 3,
-3, -1]
3
- 3
Sample Output
Explanation
The initial qualityScore of theratings is3,
and since impactFactor = 1, performing
any of the strategywill notmake any
change, so this is the maximum
qualityScore obtainable.
Hence, the answer is3
Sample Case 1

The initia
and since impactFactor1, performing
anyof the strategywill notmake any
change, so this is the maximum
qualityScore obtainable.
Hence, the answer is3,
Sample Case 1
Sample Input For Custom Testing
STDINFUNCTION
impactFactor = 3
→ratings[] size n =
4 > ratings = [-4]
Sample Output
Explanation
After performing the second strategy
(adjust ratings) on the subsegment[1, 1],
the modified ratings will be ceil - 4 / 3] =
[-1]havinga qualityScareof - 1, which is
the maximum possible.
Hence, the answer is - 1.