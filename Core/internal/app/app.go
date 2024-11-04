package app

import (
	"net/http"

	"github.com/chas3air/Saper15/internal/router"
	"github.com/gorilla/mux"
)

func Run() {
	r := mux.NewRouter()

	r.HandleFunc("/saper15/encode", router.EncodeStringHandler).Methods(http.MethodGet)
	r.HandleFunc("/saper15/decode", router.DecodeStringHandler).Methods(http.MethodGet)

	http.ListenAndServe(":13900", r)
}
