package router

import (
	"encoding/json"
	"log"
	"net/http"

	"github.com/chas3air/Saper15/internal/models"
)

var saper = models.GetSaper15Instance()

// EncodeStringHandler encodes a given string and returns the result as JSON.
func EncodeStringHandler(w http.ResponseWriter, r *http.Request) {
	log.Println("Starting encoding process...")

	queryParams := r.URL.Query()
	text := queryParams.Get("text")
	log.Println("text:", text)

	if text == "" {
		log.Println("No text provided for encoding.")
		http.Error(w, "text parameter is required", http.StatusBadRequest)
		return
	}

	encodedText := saper.Encode(text)
	if encodedText == "" {
		log.Println("Encoding resulted in an empty string.")
		http.Error(w, "encoding failed, resulting in an empty string", http.StatusInternalServerError)
		return
	}

	w.WriteHeader(http.StatusOK)
	if err := json.NewEncoder(w).Encode(encodedText); err != nil {
		log.Printf("JSON encoding error: %v", err)
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	log.Println("Successfully encoded text.")
}

// DecodeStringHandler decodes a given string and returns the result as JSON.
func DecodeStringHandler(w http.ResponseWriter, r *http.Request) {
	log.Println("Starting decoding process...")

	queryParams := r.URL.Query()
	text := queryParams.Get("text")
	log.Println("text:", text)

	if text == "" {
		log.Println("No text provided for decoding.")
		http.Error(w, "text parameter is required", http.StatusBadRequest)
		return
	}

	decodedText := saper.Decode(text)
	if decodedText == "" {
		log.Println("Decoding resulted in an empty string.")
		http.Error(w, "decoding failed, resulting in an empty string", http.StatusInternalServerError)
		return
	}

	w.WriteHeader(http.StatusOK)
	if err := json.NewEncoder(w).Encode(decodedText); err != nil {
		log.Printf("JSON encoding error: %v", err)
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	log.Println("Successfully decoded text.")
}
