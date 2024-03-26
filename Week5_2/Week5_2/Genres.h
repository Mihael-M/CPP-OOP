#pragma once

enum Genres : uint8_t {
	Action = 1 << 0,
	Comedy = 1 << 1,
	Drama = 1 << 2,
	Fantasy = 1 << 3,
	Horror = 1 << 4,
	Mystery = 1 << 5,
	Romance = 1 << 6,
	GENRES_COUNT = 1 << 7
};