package models

import (
	"log"
	"strings"

	"github.com/chas3air/Saper15/internal/config"
)

type saper struct {
	ascii         string
	shuffledAscii string
}

func GetSaper15Instance() saper {
	log.Println("Creating Saper15 instance")
	return saper{
		ascii:         config.DEFAULT_ACSII_SYMBOLS,
		shuffledAscii: config.DEFAULT_SHUFFLED_ASCII_SYMBOLS,
	}
}

func (s *saper) SetAscii(ascii string) {
	s.ascii = ascii
}

func (s *saper) SetShuffledAscii(shuffledAscii string) {
	s.shuffledAscii = shuffledAscii
}

func (s *saper) Encode(text string) string {
	var sb strings.Builder
	for _, v := range text {
		i := strings.Index(s.ascii, string(v))
		sb.WriteRune(rune(s.shuffledAscii[i]))
	}
	return sb.String()
}

func (s *saper) Decode(text string) string {
	var sb strings.Builder
	for _, v := range text {
		i := strings.Index(s.shuffledAscii, string(v))
		sb.WriteRune(rune(s.ascii[i]))
	}
	return sb.String()
}
