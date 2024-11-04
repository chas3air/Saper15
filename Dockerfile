ARG GO_VERSION=latest
FROM golang:${GO_VERSION} AS build

WORKDIR /src

COPY Core/go.mod Core/go.sum ./
RUN go mod download

COPY Core/ .

ARG TARGETARCH
RUN CGO_ENABLED=0 GOARCH=$TARGETARCH go build -o /bin/app ./cmd/app

FROM alpine:latest AS final

RUN apk --no-cache add ca-certificates tzdata
COPY --from=build /bin/app /bin/

RUN adduser -D appuser
USER appuser

EXPOSE 13900
ENTRYPOINT ["/bin/app"]