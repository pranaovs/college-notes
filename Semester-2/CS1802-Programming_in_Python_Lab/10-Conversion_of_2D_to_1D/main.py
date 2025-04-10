import numpy as np
import matplotlib.pyplot as plt


class Transform2D:
    """Handles 2D data transformation based on best-fit line orientation."""

    def __init__(self, data):

        self.x = np.asarray(list(point[0] for point in data))
        self.y = np.asarray(list(point[1] for point in data))
        self.data = np.column_stack((self.x, self.y))

    def best_fit(self) -> tuple[int, int]:
        # Find the best-fit line for the data points
        m, c = np.polyfit(self.x, self.y, 1)
        return m, c

    def transform(self):
        # Rotate the data points so the best-fit line aligns with x-axis
        m, _ = self.best_fit()
        phi = np.atan(m)  # Rotation angle based on slope

        R = np.array([[np.cos(phi), np.sin(phi)], [-np.sin(phi), np.cos(phi)]])

        transformed_data = np.dot(self.data, R.T)

        return transformed_data, R

    def compact_transform(self):
        """Transform data and zero out the second dimension to compact information."""
        transformed_data, R = self.transform()

        # Zero out y-coordinates after transformation for data compression
        transformed_data[:, 1] = 0

        return transformed_data, R


class Untransform2D:
    """Reconstructs original data from transformed representation."""

    def __init__(self, data, R):
        self.tdata = data
        self.R = R

    def reconstruct(self):
        # Transform back to original coordinate space
        reconstructed = np.dot(self.tdata, self.R)
        self.rdata = reconstructed
        return reconstructed

    def calculate_error(self, odata):
        # Calculate total squared error between original and reconstructed data
        error = np.sum((odata - self.reconstruct()) ** 2)
        return error


def main():
    # Load data from file
    with open("sample10.txt") as f:
        data = list()
        for line in f.readlines():
            try:
                data.append(list(map(int, line.split())))
            except ValueError:
                pass

    # Create transformer and perform transformations
    trsfm = Transform2D(data)
    raw_transform, _ = trsfm.transform()
    transformed_data, R = trsfm.compact_transform()

    # Reconstruct data from compact representation
    untrsfm = Untransform2D(transformed_data, R)
    reconstructed_data = untrsfm.reconstruct()

    # Calculate reconstruction error
    error = untrsfm.calculate_error(trsfm.data)

    # Print results
    print(f"Original data: \n{trsfm.data}")
    print(f"Transformed data: \n{raw_transform}")
    print(f"Compact transformed data: \n{transformed_data}")
    print(f"Reconstructed data: \n{reconstructed_data}")
    print(f"Total squared error: {error}")

    # Visualize original and reconstructed data with best-fit lines

    m1, c1 = np.polyfit(trsfm.x, trsfm.y, 1)
    plt.scatter(trsfm.x, trsfm.y)
    plt.plot(trsfm.x, m1 * trsfm.x + c1)

    ux = np.asarray([point[0] for point in reconstructed_data])
    uy = np.asarray([point[1] for point in reconstructed_data])
    m2, c2 = np.polyfit(ux, uy, 1)
    plt.scatter(ux, uy)
    plt.plot(ux, m2 * ux + c2)

    print(f"Slope difference: {m1 - m2}")
    print(f"Constant difference: {c1 - c2}")

    plt.show()


if __name__ == "__main__":
    main()
