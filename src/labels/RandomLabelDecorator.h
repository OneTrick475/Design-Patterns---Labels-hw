#pragma once
#include "Label.h"
#include <memory>
#include "TransformText.h"
#include <vector>
#include <random>

class IRandomGenerator {
public:
	virtual int getInRange(int low, int high) = 0;

	virtual ~IRandomGenerator() = default;
};

class RandomGenerator : IRandomGenerator {
	std::default_random_engine generator;

public:
	RandomGenerator() : generator(time(0)) {}

	int getInRange(int low, int high) override {
		std::uniform_int_distribution<int> distribution(low, high);
		return distribution(generator);
	}
};


class RandomLabelDecorator : public Label {
	std::unique_ptr<Label> label;
	std::vector<std::unique_ptr<TransformText>> transforms;
	std::unique_ptr<IRandomGenerator> random;

public:
	RandomLabelDecorator(std::unique_ptr<Label>&& label, std::vector<std::unique_ptr<TransformText>>&& transforms, 
		std::unique_ptr<IRandomGenerator>&& random = std::move(std::make_unique<IRandomGenerator>(RandomGenerator())));

	std::string getText() const override;

	virtual ~RandomLabelDecorator() = default;
};