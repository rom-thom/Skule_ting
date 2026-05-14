


library(readr)
library(GGally)
library(ggplot2)


groceries <- read_csv("https://www.math.ntnu.no/emner/TMA4267/2026v/assignments/groceries.csv")


head(groceries)

p <- ggpairs(groceries[, 1:3])

png("ggpairs.png", width = 1200, height = 1200, res = 150)
print(p)
dev.off()



p_central <- ggplot(groceries, aes(y = turnover, x = as.factor(central))) +
  geom_boxplot() + xlab("central")

ggsave("turnover_by_central.png",
       plot = p_central, width = 6, height = 4, dpi = 150)

p_mall <- ggplot(groceries, aes(x = as.factor(mall), y = turnover)) +
  geom_boxplot() + xlab("mall")

ggsave("turnover_by_mall.png", plot = p_mall, width = 6, height = 4, dpi = 150)




# b

groceries$log_distance <- log(groceries$distance)

model1 <- lm(turnover ~ population + log_distance, data = groceries)
summary(model1)



# c

model2 <- lm(turnover ~ population + log_distance + central*mall, data = groceries)

summary(model2)