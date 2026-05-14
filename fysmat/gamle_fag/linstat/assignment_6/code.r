
library(readr)
LMdata <- read.csv("https://www.math.ntnu.no/emner/TMA4267/2026v/A6lmdataInfl.csv")
dim(LMdata); head(LMdata); tail(LMdata)

dim(LMdata)
head(LMdata)
tail(LMdata)
table(LMdata$group)
table(LMdata$group, LMdata$month)
plot(LMdata$month, LMdata$dep)