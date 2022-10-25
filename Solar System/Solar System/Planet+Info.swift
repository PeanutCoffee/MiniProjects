
import Foundation

extension Planet {
  var moonCount: Int {
    switch self {
    case .mercury:
      return 0
    case .venus:
      return 0
    case .earth:
      return 1
    case .mars:
      return 2
    case .saturn:
      return 62
    }
  }

  var yearLength: String {
    switch self {
    case .mercury:
      return "88 Earth days"
    case .venus:
      return "225 Earth days"
    case .earth:
      return "365.25 days"
    case .mars:
      return "1.88 Earth years"
    case .saturn:
      return "29.45 earth years"
    }
  }

  var namesake: String {
    switch self {
    case .mercury:
      return "Roman god of speed"
    case .venus:
      return "Roman goddess of love"
    case .earth:
      return "The ground"
    case .mars:
      return "Roman god of war"
    case .saturn:
      return "Roman god of agriculture"
    }
  }
}
