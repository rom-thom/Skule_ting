


X <- matrix(c(
  1,0,0,
  1,0,0,
  1,0,1,
  1,0,1,
  1,1,0,
  1,1,0,
  1,1,1,
  1,1,1
), ncol = 3, byrow = TRUE)



dat <- data.frame(
  x1 = X[,2], # light
  x2 = X[,3] # noise
)



# True parameters
beta0 <- 225
beta1 <- -30
beta2 <- 45
sigma <- 10



# a

eps <- rnorm(n = nrow(dat), mean = 0, sd = sigma)


dat$Y <- beta0 + beta1 * dat$x1 + beta2 * dat$x2 + eps

# Model:
fit <- lm(Y ~ x1 + x2, data = dat)

# Estimated coefficients
beta_hat <- coef(fit)

# Estimated variance s**2
s2_hat <- summary(fit)$sigma**2

beta_hat
s2_hat


# Compare to true values
cbind(
  true = c(beta0, beta1, beta2),
  estimated = beta_hat
)

c(true_sigma2 = sigma**2, estimated_s2 = s2_hat)



# b


b0 <- numeric(1000)
b1 <- numeric(1000)
b2 <- numeric(1000)
s2 <- numeric(1000)





for (b in 1:1000) {
  eps <- rnorm(nrow(dat), mean = 0, sd = sigma)
  Y <- beta0 + beta1 * dat$x1 + beta2 * dat$x2 + eps

  fit <- lm(Y ~ x1 + x2, data = data.frame(Y=Y, x1=dat$x1, x2=dat$x2))

  co <- coef(fit)
  b0[b] <- co[1]
  b1[b] <- co[2]
  b2[b] <- co[3]
  s2[b] <- summary(fit)$sigma^2
}

# ---- Plots ----
par(mfrow=c(2,2))

hist(b0, breaks=30, main=expression(hat(beta)[0]), xlab="")
abline(v=beta0, lwd=2)

hist(b1, breaks=30, main=expression(hat(beta)[1]), xlab="")
abline(v=beta1, lwd=2)

hist(b2, breaks=30, main=expression(hat(beta)[2]), xlab="")
abline(v=beta2, lwd=2)

hist(5*s2/(sigma^2), breaks=30,
     main=expression(5*hat(s)^2/sigma^2),
     xlab="")
abline(v=5, lwd=2)  # E[5*s^2/sigma^2] = 5

par(mfrow=c(1,1))

