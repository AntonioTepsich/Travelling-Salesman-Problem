## Made by: ##

Antonio Tepsich

Vianca Mónaco 

Maximo Gubitosi

Romanella Colombini

# Travelling Salesman Problem: Genetic Algorithms #

Genetic algorithms are a search technique based on Darwin's evolutionary theory. In this paper, such heuristics were implemented, using the object-oriented programming paradigm, in order to solve the Travelling Salesman Problem; that problem focuses on finding the optimal route by which a traveller can travel through a series of cities in the shortest possible time or with the shortest possible distance.

### Implementation: ###

Initially, the following classes were considered:

- City: contains the coordinates of each city, its id (used to access the correct values of a matrix that will have the distances between the cities).
- Path: the roads.
- Traveler: contains several methods implemented to solve the traveller problem based on a genetic algorithm and the population.

However, in the course of development, we realised that we would need to create more classes for other objects that would also be used:

- Fitness: contains the functions to calculate the fitness of each individual.
- DistanceMatrix: creates a dynamic matrix used to store distances between cities.
- DataGuardian: stores the total fitness data of the generations in order to have the possibility to generate a graph at the end of the programme.

To begin with, two functions were used to create the population dynamically; one of them created a route randomly, while the other created instances of it to be stored in a vector representing the population. However, our goal was to apply classes to address the design of the solution to the problem, so we considered creating another class that creates the population randomly in its constructor. It was decided to implement the program with composition relations between the classes, in this way it would only be enough to create an object, TravelerGeneticAlgorithm, to start executing the code.

Even so, we noticed the need to generalise and abstract the algorithm, so we tried to identify the classes from which (the ones we had already created) could be derived, and also how to create these new structures so that they could be used in the future. The result was the following:


[Class Diagram.](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=UMLCLASES.drawio#R7V1rc9o4F%2F41zKSdCeM78BGSNtvd9n3TJN12P2UU7IC3xqK2SUJ%2F%2FUq25IskXyAWEPBOZ4OFLMs6R0fPec6R6OkXi5erACznX6DteD1NsV96%2BmVP01R1aKE%2FuGSdlFiqnhTMAtcmlbKCW%2Fe3kxTqCildubYTFipGEHqRuywWTqHvO9OoUAaCAD4Xqz1Cr%2FjUJZg5XMHtFHh86XfXjuZJqaYoSvbFH447m0fsNwtAa5OCcA5s%2BJwr0j%2F09IsAwij5tHi5cDw8enRgvn9af%2Fc%2B%2F7Su%2Fvwa%2FgLfJn%2Fd%2Fe%2Fv86Sxj5vckr5D4PjR1k3%2F%2Fvn48Y%2B%2FjX9%2FLK8%2Ffn1WrsYPf56TW5Qn4K3IgF05vhO507E3g4EbzRfk3aM1HdHw2V14wEdXk0foR7fkGzQcE%2BC5Mx99nqJ%2BOgEqeHIC1BbwxuSLCC5R6XTuevZnsIYr%2FDZhBKY%2F6dVkjp76GzULPPSVigrQ10FE9EqzCjVu8Z2oWEGlgROiOtd0iNS06DMII1JnCj0PLEP3Ie4wrrIAwcz1JzCK4II2BFe%2B7djkKpV5fBEF8GeqRvj%2BhoIhAsSj4bzk9JII6sqBCycK1qgK%2BTbVOTLrVHr9nOmwOiRl87z6qqQQkHkzS9tOH3eD5hnwZ2gQsufpzPMMwfMs0fOs4uOAhwTvg8iZ4GEM8wqJPuReNSuK1XQDlVU5le1p%2BhIuVx6IXOjfo%2B96%2Bhj9%2Fzote88pMZJDlFNYz3mMStU1XIKp688%2Bx3UujazkhowDLoLo3kcvVpW5a9uOH6tSBCKQaBvWnyV0%2FSgeKHOC%2FqHhvFD6Zs9EHbpA12p2jf7h6kF0AX2kdcCN1ctBqvzsYHUWKF7l9K5XvHVRnrV6ZpWrWUHgm0rXEEiXkZ3nxsZnHi0yG8FOzBrBLpCIcHNUkndY0JfnKidtnZe2LpCsBx4c7xqGLtY2VBYkdRmJ70uoptZMqMMWZHpjf3W9bwv7xvg9mZyffxoM5%2Beqyi8zPW1y5UTZFD17J5i0loeH5SEoyN%2F6tYLx2ALbRmJJblOWL%2FG8n8QLNzbquXJ6B%2Fo0S%2F5OaNsuLbv2wPoMSwRNRYR24AoJl3QpjGz8QR9HqyU2mhZYYLPgkSbl9DF96BOy1jAoPjXpXloW3%2FA%2B7jkp8R%2FCpbCRtLN0JPLNoqX%2FPddo%2FpI2gLTAzTWxOyndOMvg1vHQ22CVQeLCInqCSPsOoWfQXiUd%2B%2BTb7pNrr4AnkkpVX3fR%2BaRhZNV8WpbrL9H5%2FJjm1WVyi8wTQg%2BZEOpu%2BLKKQKOK35Y2wg2f%2FEd4xkq1oLB07PIvIB5S8ZqfWzearhIxkixdyLFZB6sIhglIzRakC%2BihSadf%2BjBesErMdlOLX2rerYbYUDUrsOGrFm2LM%2B93AXhCKhJs600onTfRojehFtG9YQo0ZtCeN6Ey3oQ%2BPFxvYsCp7jlmLVIn4hLhvKsVCGwXnK4bYTXWuAo3QqhgstyIUedGtC5UkRshEqo8N0Lk%2Bh85cuchkKjZxshdJhZOAFmrrTfB%2ByIc%2BAZfc3PnQfTiEjonbUzrvY62RdjUeWn7uXU%2BUNvPq3ClOL05GifJ2thJEi1e8pwkVavHJI5vj3HQC109eBC7IxNURPwVVUkuP7r4wU0ciqL34dgzh%2FpXjvcAnz9kBZO4AH1BxbuxOxLCVTB16vEG7kUl2hA5CYGDOcGnYkyvwim5hjEgSB0gpeiQaIpebCLpPLkrH0NjGtKZhnSd0RbkXs4wrck0hIQK1rlqZG6Udph7zqgQ20MfkhbbDazwvlDGxjZ13LswYIuOu6kMC2ogDAOKHGnDrADh5Y67aRbV7qDDgEOBOcVxwPtfK%2BBHbrQmPgAS%2Fj2aWqiHupqsoYVooT7mAXtWNVk0C5DMSvF1ocXwfub4ONNB0B51OOgNBK7PmGL09xF36KMboZZC5hERcha9%2B8fkuyzKST2K02QmUpv1KmpCpNKqZkgCAprekRPty1UVkZoiwVry%2BAmRYJPJj%2ByHEObjaXpOBIlncyzLRjGbNID6lZg76lykBq8mUBJ3qVgqsZdMmLfURu65t%2FWkymH0MxnVEIdXwm5M2xtTsvTSIc2txIfTxzsMBJiOprzigXTztmiaEpvUkLzbeTepbXoLE6gIRfPz6EBHl9iotzC2AuMkIOz23mVC74nMwGH18w5eO8G0noLcecfGto3m0Vk1Ab1RN7m8nXb6nWu2SCLX5TyJe7llekwpj3Mw3G%2FiLpT7fJQsqOUxjDbYX7FzYHLOAU2S2ZxlO%2BH0mBr1KCfeylk2Jj3GahorsCoYgreXHSPWWp4TPjWuos4eVcz2V%2BfHyKMqROxpSZzyTUYIt5GKbjSTChv0aVEsDfKWDjBGyMT0trfIEmJ%2F5sgsWnedmVRNY3%2FmyOgP1EJb5oBpq6XwH9dnq%2BXwn1D5aHApp3wZQm6KTE44%2Ftc%2BMhmy8ThB%2FC%2FN0S3i2K3if4e6DVCsrsKNgDPHTwKA9%2BXhP1QHLoA49JcnAkSBvjT%2Bpo9Tzk3w9RI5viV1jjJQt9VynNtF3RAkCZW9Coa%2Fbjmmq2%2BHflsV7KihFZOGfoURWEyt4wVGHEcrbFXiAwVF%2Fr2kcsqG1d5wFVuo8sBOs4hKceMWebuMimf4LrY2fcMso7qmdvx6zWqT99v0xSqb5TizqqzLHe0TLCEHy1KWT2WP21ZGg6fwhEajnQROcQ%2F5zenX%2BJCQjrTbAzQ2ilC18Z62UYV6HAlpR5%2FZwZYNLZCxKR7dLWmnichYUVzoiBaFapHsn7HTRETqITN2aMCD9Q98c18f0ut%2FcNN9RVNpweULbT6%2BWuevEM5z0ejh5esyc2m35ACZjQOV627CrtUD%2B53wikNmRdh6T8GIXVrYFaolUrHsOZJJRZ7RVvp9KvpsjrCWpsZCPRBAkiwaE4RyZvG0YCxPDL%2FIPNNSVSVnzZGn9dLDttpHKarCaok27FvGQDGHQ003Ncrztm%2BX6HNz404cuqZwtWNy21QEg8GrjanctOIRU7l6x7NthY70dghUaYBVL0%2BIz2c2XQBvStmmzSkhnj%2FJ0e6VZE%2BWDxaGSENoF%2Fi0sOo9Nm8RV9dojgBXi6l3abha57kWmi614TrW0S6trmMWgyIbnz613Tr2pogXnc%2FxO4%2BJ4ihwX7Ite5cu0h1%2F6nyJy4%2F1VKHt7NLmFIy040nFHey4NRmC3fsRpbqQW3sFMuGBRowmjhBKVEu26fogj6LT3xpF15NNqJWJTAJNphpsDpO6JU%2BmsqcTcMn6LRFl3IPoaRxymTKDZ2yQVWmKcju2pk2Uq3ZsTYWiCk%2FecO04oY4kzRzP8ma0w7HIW94MUR5kh0hfK1izqWClZR8aIlYUZ4d9suNY78nNtaZ5gxLnGk9oXuCThjoqah%2BLdEdFVWgqz59iKurlnkk%2FpXnp%2BMv1fRO6%2BxRpKaMkr2BDWkriWsEzjx0IeL1gm1oUabSUIaIbMQb4cfaOi3OxWeT%2FnB0n41QnNMFm%2F90yTkaDXdOnxTiViUwG46S2xjhpu2Kc2AftiHHic7OKoakO1x5CqpA5aOj3pFbuiMknOlFKQqw5%2FPpesA8KV8W%2FKZunqrg6SFWOlMoabYpid5z0YXZUlgzBDvdOZdHwLgdji%2BtNcXOkaAInd92gKdxsmyaaPGzFk5nPjYMWEic0z5flf1Crwxf7wBcMbTYQ0Fia8KcxTgFeiGkzzFQBz8NHvN%2FnToDo1ezNLvm1p%2BOxQObGvJhQs%2BR54mbHi8kQrCg4JhSsPEQhJMbGtv3%2FZKpeOf4GBxggpMDf9054QEw3vSvjcTue3jzRxm8tyzFtcBkHGXKyyHFuGkUEtDaCKAvo23dzfMpDASyoBi0gDJ3KkG5oVs7hDPrAyzNvTTe19V5Dx5Uu%2FJStoxxTrw22zWB%2FWknLTknb%2BIQ1lW2L2R7XEt1mcJvy0j6Xda3%2BFkkcnckn2%2FAazpsYbjtl0VA0P9mXtzmPSOMZEyO0O0WwKwvNGgPmJ5JGw75lcnZJ361Z4onVYzBL2dbxXm7fuNIf6r3dbxtvsBl8D%2BbQssrVcVNzONTq2yqxiK2ZH4unW9XeB62HXMGx1QTrnIwhGjKLl2odgCGyeEK1SnxvzyS9IaSkKgzx8hrbwGcoj0ZSsJKqDHXhg8p7pphVN0jCSRbPNHaGqiRv7iAtFU%2B8fQv5rBXeQjFmyQbhPB5ClbVeBLukFwl2GRjGQYKXJMl%2BNwkT3NkUSCHokQwbGyadtXKCxqSjFp71a1eZXtwoxcHoc6JKpjUg15km4Yt17mLnZyeZJSnVdKVT%2BtqAnismQ7d0JrPFUpQtFUtjFMtgwxGtJeMwD7L0imSc7HbaPnx8DB1Jes3TXXKMJFILBS3jBUupJOp9cJZSLyEpcxquDCp%2B9LVtj88Y9Uf5%2FxgKvLG%2BG%2BzP0shR9zT8V3xMObwTd6t82o6q6u9zMh07SdMvTuCaySt9npYFE2T6XNrI6LM%2FpaH2t%2FS5%2BMYG7FnDG8%2FJ1rV6IPL4O%2B8nJ8QSEbbv%2BaDLAOIDwTMBB2A5%2FwJtB9f4Dw%3D%3D)

Abstracting the algorithm by implementing the abstract classes GeneticAlgorithm, Population, Fitness, Individual and Gen allowed us to provide a general structure that can be implemented in different problems. The identified entities were separated into classes in order to divide the different tasks needed to tackle the problem. In turn, considering that the high level module class GeneticAlgorithm, which implements the heuristics of the genetic algorithm in a general way, works with the low level module classes Population, Individual and Gen, it was decided to abstract also this second group of classes so that, once again, the code can be implemented in a general way.

Once the declarations are complete, we start implementing the algorithm's own functions.

We chose to separate the stages of natural selection into different methods, the TravelerGeneticAlgorithm class interacts with these and assembles the process.

At the beginning, SelectionRepr() is in charge of choosing the individuals to breed based on their fitness: the best are bred with the best, the worst with the worst and we eliminate the half that had the highest fitness (i.e. those with the "longest" route); every a certain number of generations (defined value CRAZY_TIME), the individuals are not bred with the above mentioned strategy, but the cross is random.

When the "parent" individuals are chosen, they are used in the Reproduction() function, which selects genes from both parent individuals to create the offspring. The genes are chosen randomly, a "stretch" of one parent's genome is selected and the other parent is taken into account to obtain the rest of the genes. The stretch chosen from the first individual is at least 20 per cent of its genome in length and a maximum of 80 per cent of its genome in length.


Breeding doubles the number of individuals in the population, a percentage of these individuals are mutated, and finally, the vector is sorted with the different pathways and the worst half is eliminated.

[Sequence Diagram](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=secuencia.drawio#R5Vtbb9s2FP41BroCMSRRNz86SZt1aLeiydD1qWAk2iZKiwJFJfF%2B%2FUiJupK2FcdyLutDYR5RFPWdy3fOETMBF%2BuHKwbT1RcaIzJxrPhhAi4njhOEofhfCjalwLfcUrBkOC5FdiO4xv8iJbSUNMcxyjoTOaWE47QrjGiSoIh3ZJAxet%2BdtqCk%2B9QULpEmuI4g0aXfccxXpTT0rEb%2BO8LLVfVk21JX1rCarATZCsb0viUCHybgglHKy1%2FrhwtEJHYVLuV9H7dcrTfGUMKH3PAHnn%2FO3QwQwvCfZ%2FDnF%2Bf7zZmtlrmDJFdvrHbLNxUEjOZJjOQq9gSc368wR9cpjOTVe6FzIVvxNVGX4W1GSc7RnEVKmYW0GblimHFGf9V4yglqF4hx9LD1%2FewaNWFtiK4RZxsxRd3g2cqylKUBoIC%2Fb%2FTmhEq2auls5ilzUaayrJdu0BQ%2FFKCPANd9M9jabhdbO%2FBOhy1I8vOPD2wWbT5bafLX9xsHXp3pdgvJkjLMV%2BsJmN8weIcIYlcoQRxH8%2FpSH3%2FhlKn8ma%2FJZ7xABCdidJ4ihsU2ERNXiBJ%2FbWTnIthwKGRMIRxRQmCa4dtiWUtIGIpyluE79A1lpXIKaa1tOaoDgrVDbZqODJrcqja%2Fq7XQ4BCWQWnuzBpJa85%2Bj0gpTnjxXO984l32tEEZX9ElTSBp6%2BOJuO40sMFgz%2FwO2L7uIbYBaxCO5SFAwzolcPPuNw1x%2BYpYMN6c4GUiRLeUc7ousIOMzyWJSuTFQkKGkriS3BIa%2FaqmqRAUHht%2FsfYS7ZqnLAjFHR7XtcQQgVw4ZDdDMICubv0q7bDRLjBrt1ogozmLkLqnp7h6E4frcgCTvFq%2FsS17X5QyOY7tjBWkPB1sMP9K01waEE3%2BZxziBl0ScQxplW1iEWCNpSD%2F9XiD92i4vQ7awUBnOAZjmwuE%2FVi3KCEiMMtw1E1b0QPm%2F7R%2B%2F5CgTi3HVePLB4VyMdi0Bi3tFDJjqDfadxmP99GGroUWzp4B50r2RDKp0%2BcqnfbAIDrZv5Afdhcq6VNbSOgLblrTlLts3%2FDMvOGt%2B%2BrPV%2FtqLLHcwaEkaTRVPeH5hlJ2LeqASMbtd0tRDLAyhIO5XCzhejIk3JT3qi6VFkXCxoo40c%2BX1jiO5e0iYIs4DZsArgchmHOaNaVbGVYuKKHSwhNaEMeWiPGocm3WK9c8QxgJDPZ9DE416kbnVEJpKiTv8oRjeTtfIfmOLZq1CqTEwsIwrZjmAtj4rSosGFBfg1MqbADHtiA%2FhG7HaVQETjdbcYYRqDsWjoExKNE4j5SRv%2FuUxPgOxzkk7yeOeIjVEujmLsnvWg0bXD80UpMnELSQPpKlMMLJ8nMxunTM1Vw3CxKws01N3nLwo8XPxYWp5VVMXjK7E4JjMXu7%2BttlpodkAK7ZkJ5M7UHXAPtZ8BZqfzwjz4zP2c7IvfndbvE4jBy%2B0iDid4t9YA8LIqMF45mG45ecFyxpaOe8mAhxqE%2BHg%2FX1ZF%2Ftdh6cfhV1JF91LPNzRvW9ykCHGU3LJLa2Aw2mUCv%2FzJpKNNsWMLUttxI0RFCMNu3R4UXe3t6gbzablhuHxyro%2BhFjNg1mrX%2FD2oXaul4VUpp1uwttqe%2BOZkSOZkRF3l7UT1XmDqUppSjCC1H5C0UhJjNv%2BV3VseiiSu19IgPMLRO%2FlrxQsw%2FX8gNXcpulRfRvZf5Fyr%2BmsVhSBJr9KX8%2Fke%2Bl7b0ot7Ue0BlogQnppfvGGqAbE4%2FAQR4Y8DXTMbbdRiIh29CEBvMmWdXU9OL7ok9SUGA%2FZ1%2FUrCFD57qvlBM1RvdAu8PAhnZG7YGVXTga2nppNy7BWn7QJVgQhqcj2B0WdwqG9UCPCYPZNDywa%2Br3YqvXT9xHZlVHT8122cvLrYv8Z66L6q9ZDZDX4nU4TJqu7xsskCo8T18hgX6fbKQKqXrOqBVS5XWv3Q3d525POPqXl7%2FTGHL0KVnQN%2BmAzrM54IlaFOAULQpHryhKu7mhHJKPmCcoy0bIpUQq5fVSqSA8qFfRaoLb3SZ4UI%2BP%2F3n7RB2Naa%2FCcZ3Z1AkHmZ%2Bevtmzqee3GiLdlYE1dUHrqjsoH3uskYPQ7T9256Zda%2Bf8kZzCePzoEnJ4lUMWY3isA0h7DhsfWofTnMsnXdTn8UerwPvqNKWjpjPJ4x2WcV7OyaQnIevaPf8ceAzJGw1YvdbmeUpQ3UQkZV8v4pR1ZeW5gVqmWo8X%2B%2FuRpsWuUPK%2Bv1R39DSmoilK5J5htqr%2FJkBcbp2tPZwilGoFM3X7KHWP96mE4XcLdK%2By%2FcdSRbhnnS1k0KxTTaSLRYbGKeD1D5vzOP5LqBgSIoykSl3o3c8lSn4usOGg0YFJzIvKEfxemJi508A%2BTOuuHfTW8gap%2FWiHx%2FSezBXi4ySiL0mHoOe2rnekT1Wu507DYacRj6bDAYdVVXKk06bhS8%2FQz0aqJr2RH8Yuz2ytSgWN5JsiS1CwOhdZXZNPEXiLyFea4fKI4iUr55oaDyJNEAmWeAmIC4tBMOP3KCsID7Oy8yXEQnfy%2FY6SbHm%2B2U7aJmnKtR6dEYhh80eRpWk0f1kKPvwH).

The process is repeated until the requested number of generations is met or the threshold of change from one generation to the next is sufficiently small.