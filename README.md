# What is Saper15

Saper15 is an open source encryption system. It was designed to achieve greater securuty in the transmission of genetic data and its eranization

# How  to use this image
```
  $docker pull chas3air/saper15:latest
  $docker run --name some-saper15 -p 13900:13900 --rm  chas3air/saper15:latest
```

Alternatively, a simple `Dockerfile` can be used to generate a new image includes the additional necessary content you need
```
  FROM chas3air/saper15:latest
  ENV ASCII_SYMBOLS="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !#$%&"'()*+,./:;<=>?@[]^-|{}~0123456789_"
  ENV SHUFFLED_ASCII="m9ev5oVDS?TE->g^BL@'dbf.K:RA};q&ch3yM|*kW$Z8X61l+x#sYn/wr=\"I(uGjzN 0CiJ<{Q4Pt)[]a,O~p_7U!2%FH"
```

Here is an example using docker-compose.yml
```
  saper:
    image: chas3air/saper15:latest
  ports:
    - 13900:13900
  environment:
    ASCII_SYMBOLS: "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !#$%&\"'()*+,./:;<=>?@[]^`-|{}~0123456789_"
    SHUFFLED_ASCII: "m9ev5oVDS?TE->g^BL@'dbf.K:RA};q&ch3yM|*kW$Z8X61l+x#sYn/wr=\"I(uGjzN 0CiJ<{Q4Pt)[`]a,O~p_7U!2%FH"
  restart: unless-stopped
```